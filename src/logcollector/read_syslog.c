/* Copyright (C) 2015-2020, Wazuh Inc.
 * Copyright (C) 2009 Trend Micro Inc.
 * All right reserved.
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation
 */

/* Read the syslog */

#include "shared.h"
#include "logcollector.h"
#include "os_crypto/sha1/sha1_op.h"


/* Read syslog files */
void *read_syslog(logreader *lf, int *rc, int drop_it) {
    int __ms = 0;
    int __ms_reported = 0;
    char str[OS_MAXSTR + 1];
    fpos_t fp_pos;
    int lines = 0;
    w_offset_t offset = 0;
    w_offset_t rbytes = 0;

    str[OS_MAXSTR] = '\0';
    *rc = 0;

    /* Get initial file location */
    fgetpos(lf->fp, &fp_pos);

    SHA_CTX context;
#ifdef WIN32
    w_get_hash_context(lf->file, &context, fp_pos);
#else
    w_get_hash_context(lf->file, &context, fp_pos.__pos);
#endif

    for (offset = w_ftell(lf->fp); can_read() && fgets(str, OS_MAXSTR - OS_LOG_HEADER, lf->fp) != NULL && (!maximum_lines || lines < maximum_lines) && offset >= 0; offset += rbytes) {
        rbytes = w_ftell(lf->fp) - offset;
        lines++;

        OS_SHA1_Stream(&context, NULL, str);

        /* Flow control */
        if (rbytes <= 0) {
            break;
        }

        /* Get the last occurrence of \n */
        if (str[rbytes - 1] == '\n') {
            str[rbytes - 1] = '\0';

            if ((int64_t)strlen(str) != rbytes - 1)
            {
                mdebug2("Line in '%s' contains some zero-bytes (valid=" FTELL_TT "/ total=" FTELL_TT "). Dropping line.", lf->file, FTELL_INT64 strlen(str), FTELL_INT64 rbytes - 1);
                continue;
            }
        }

        /* If we didn't get the new line, because the
         * size is large, send what we got so far.
         */
        else if (rbytes == OS_MAXSTR - OS_LOG_HEADER - 1) {
            /* Message size > maximum allowed */
            __ms = 1;
            str[rbytes - 1] = '\0';
        } else {
            /* We may not have gotten a line feed
             * because we reached EOF.
             */
             if (feof(lf->fp)) {
                /* Message not complete. Return. */
                mdebug2("Message not complete from '%s'. Trying again: '%.*s'%s", lf->file, sample_log_length, str, rbytes > sample_log_length ? "..." : "");
                fsetpos(lf->fp, &fp_pos);
                break;
            }
        }

#ifdef WIN32
        char * p;

        if ((p = strrchr(str, '\r')) != NULL) {
            *p = '\0';
        }

        /* Look for empty string (only on Windows) */
        if (rbytes <= 2) {
            fgetpos(lf->fp, &fp_pos);
            continue;
        }

        /* Windows can have comment on their logs */
        if (str[0] == '#') {
            fgetpos(lf->fp, &fp_pos);
            continue;
        }
#endif

        mdebug2("Reading syslog message: '%.*s'%s", sample_log_length, str, rbytes > sample_log_length ? "..." : "");

        /* Send message to queue */
        if (drop_it == 0) {
            w_msg_hash_queues_push(str, lf->file, rbytes, lf->log_target, LOCALFILE_MQ);
        }
        /* Incorrect message size */
        if (__ms) {
            // strlen(str) >= (OS_MAXSTR - OS_LOG_HEADER - 2)
            // truncate str before logging to ossec.log

            if (!__ms_reported) {
                merror("Large message size from file '%s' (length = " FTELL_TT "): '%.*s'...", lf->file, FTELL_INT64 rbytes, sample_log_length, str);
                __ms_reported = 1;
            } else {
                mdebug2("Large message size from file '%s' (length = " FTELL_TT "): '%.*s'...", lf->file, FTELL_INT64 rbytes, sample_log_length, str);
            }

            for (offset += rbytes; fgets(str, OS_MAXSTR - 2, lf->fp) != NULL; offset += rbytes) {
                rbytes = w_ftell(lf->fp) - offset;

                /* Flow control */
                if (rbytes <= 0) {
                    break;
                }

                /* Get the last occurrence of \n */
                if (str[rbytes - 1] == '\n') {
                    break;
                }
            }
            __ms = 0;
        }
        fgetpos(lf->fp, &fp_pos);       
    }
    /* For Windows fpos_t is a __int64 type. In contrast, for Linux is a __fpos_t type */
#ifdef WIN32
    w_update_file_status(lf->file, fp_pos, &context);
#else
    w_update_file_status(lf->file, fp_pos.__pos, &context);
#endif

    mdebug2("Read %d lines from %s", lines, lf->file);
    return (NULL);
}
