/*
 * Copyright (C) 2015-2020, Wazuh Inc.
 * January 17, 2018.
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation.
 */

#ifndef DEBUG_MESSAGES_H
#define DEBUG_MESSAGES_H

/* vulnerability-detector messages*/
#define VU_STARTING_UPDATE    "(5400): Starting '%s' database update."
#define VU_UPDATING_NVD_YEAR  "(5401): Synchronizing the year '%d' of the vulnerability database."
#define VU_UPDATING_RH_YEAR   "(5402): Synchronizing the page '%d' from the vulnerability database."
#define VU_LOCAL_FETCH        "(5403): Fetching feed from '%s'"
#define VU_DOWNLOAD_START     "(5404): Trying to download '%s'"
#define VU_DOWNLOAD_FAIL      "(5405): The download can not be completed. Retrying in '%d' seconds."
#define VU_UPDATE_DATE        "(5406): The feed '%s' is in its latest version. Update date: '%s'"
#define VU_DB_TIMESTAMP_FEED  "(5407): The feed '%s%s' is outdated. Fetching the last version."
#define VU_UPDATE_JSON_FEED   "(5408): Updating from '%s'"
#define VU_DISCARD_MATCH_N    "(5409): The matching configuration node '%s' from '%s' will be discarded because it is contemplated by '%s' (%s%s%s%s%s%s%s)."
#define VU_UNEXP_JSON_KEY     "(5410): Unexpected JSON key: '%s'"
#define VU_UPDATE_PRE         "(5411): Starting preparse step of feed '%s'"
#define VU_UPDATE_PAR         "(5412): Starting parse step of feed '%s'"
#define VU_OVAL_OBJ_INV       "(5413): Invalid OVAL object type: '%s'"
#define VU_START_REFRESH_DB   "(5414): Refreshing '%s' databases."
#define VU_UPDATE_VU          "(5415): Inserting vulnerabilities."
#define VU_INS_CPES_SEC       "(5416): Inserting CPEs section."
#define VU_INS_CPES_DIC       "(5417): Inserting Wazuh's CPE dictonary."
#define VU_INS_MSU            "(5418): Inserting Microsoft Security Update dictonary."
#define VU_INS_NVD_SEC        "(5419): Inserting NVD vulnerabilities section."
#define VU_INS_RH_SEC         "(5420): Inserting RedHat vulnerabilities section."
#define VU_INDEX_TIME         "(5421): It took '%ld' seconds to '%s' vulnerabilities."
#define VU_INS_TEST_SEC       "(5422): Inserting '%s' vulnerabilities references."
#define VU_UPDATE_VU_CO       "(5423): Inserting '%s' vulnerabilities conditions."
#define VU_UPDATE_PACK_NAME   "(5424): Inserting '%s' vulnerabilities package names."
#define VU_INS_VARIABLES      "(5425): Inserting '%s' vulnerabilities package variables."
#define VU_UPDATE_VU_INFO     "(5426): Inserting '%s' vulnerabilities information."
#define VU_STOP_REFRESH_DB    "(5427): Refresh of '%s' database finished."
#define VU_DOWNLOAD_PAGE_SUC  "(5428): Page '%d' successfully downloaded."
#define VU_NVD_UPD_CANCEL     "(5429): The '%s' update has failed, so the NVD feed will not be updated."
#define VU_ENDING_UPDATE      "(5430): The update of the '%s' feed finished successfully."
#define VU_START_SCAN         "(5431): Starting vulnerability scan."
#define VU_AG_NEVER_CON       "(5432): Agent '%s' never connected."
#define VU_AGENT_UNSOPPORTED  "(5433): Agent '%.3d' has an unsupported Wazuh version: '%s'"
#define VU_UNS_OS_VERSION     "(5434): Agent '%.3d' has an unsupported OS version: '%s'"
#define VU_AG_NO_TARGET       "(5435): The analysis can not be launched because there are no target agents."
/* ID 5436 is available */
#define VU_AGENT_SOFTWARE_REQ "(5437): Collecting agent '%.3d' software."
#define VU_AG_FULL_SCAN       "(5438): A full scan will be run on agent '%.3d'"
#define VU_AG_PART_SCAN       "(5439): A partial scan will be run on agent '%.3d'"
#define VU_NO_PACKAGE_SCAN    "(5440): The package inventory of the agent '%.3d' is not available, but a hotfix analysis will be launched."
#define VU_SOCKET_RETRY       "(5441): Unable to connect to socket '%s'. Waiting '%d' seconds."
#define VU_NO_HOTFIX_AVAIL    "(5442): It is not possible to perform a hotfix scan on agent '%.3d'"
#define VU_OSINFO_DISABLED    "(5443): Unable to get the OS release for agent '%.3d'. It may not have the OS inventory enabled."
#define VU_OSINFOLNX_DISABLED "(5444): Unable to get the OS version and release for agent '%.3d'. It may not have the OS inventory enabled."
#define VU_NO_SOFTWARE        "(5445): No changes have been found with respect to the last package inventory or no packages have been indexed for agent '%.3d'"
#define VU_AGENT_CPE_RECV     "(5446): The CPE '%s' from the agent '%.3d' was indexed."
#define VU_CPE_GENERATED      "(5447): CPE generated from vendor '%s' and product '%s': '%s'"
#define VU_GEN_CPE_COUNT      "(5448): CPEs generated for agent '%.3d': '%d/%d'"
#define VU_INSERT_DATA_ERR    "(5449): It was not possible to insert '%s' in the agent software table."
#define VU_START_AG_AN        "(5450): Analyzing agent '%.3d' vulnerabilities."
#define VU_START_NVD_AG_AN    "(5451): Analyzing NVD vulnerabilities for agent '%.3d'"
#define VU_FIND_NVD_VULN_ERR  "(5452): It was not possible to look for the vulnerabilities of '%s' (%s) in the NVD."
#define VU_HOTFIX_INSTALLED   "(5453): Agent '%.3d' has installed '%s' that corrects the vulnerability '%s'"
#define VU_NO_HOTFIX_FEED     "(5454): We have not found a hotfix that solves '%s' for agent '%.3d' in the Microsoft feed, so it is not possible to know it is vulnerable."
#define VU_VULN_NVD_AG_COUNT  "(5455): The NVD found a total of '%d' potential vulnerabilities for agent '%.3d'"
#define VU_START_OVAL_AG_AN   "(5456): Analyzing OVAL vulnerabilities for agent '%.3d'"
#define VU_VULN_OVAL_AG_COUNT "(5457): The OVAL found a total of '%d' potential vulnerabilities for agent '%.3d'"
#define VU_PACKAGE_INSERT     "(5458): Package '%s' inserted into the vulnerability '%s'. Version (%s) '%s' '%s' (feed '%s')."
#define VU_DUPLICATED_PACKAGE "(5459): Trying to insert duplicated package '%s' into the vulnerability '%s'. Version (%s) '%s' '%s' (feed '%s')."
#define VU_PACKAGE_NOT_VULN   "(5460): Package '%s' not vulnerable to '%s'. Version (%s) not '%s' '%s' (feed '%s')."
#define VU_START_VUL_AG_FIL   "(5461): Filtering vulnerabilities obtained for agent '%.3d'"
#define VU_PACKAGE_NOT_AFF    "(5462): Package '%s' not vulnerable to '%s' since it is not affected (feed '%s')."
#define VU_PACKAGE_NO_DEP     "(5463): Package '%s' not vulnerable to '%s' since it don't meet its '%s' dependency on package with ID '%d'"
#define VU_PACKAGE_DEP_NOT_VU "(5464): Package '%s' not vulnerable to '%s' since it is a dependency not vulnerable."
#define VU_VULN_FILTER_AG     "(5465): A total of '%d' potential vulnerabilities have been discarded for agent '%.3d'"
#define VU_START_VUL_AG_SEND  "(5466): Sending vulnerabilities report for agent '%.3d'"
#define VU_HOTFIX_VUL         "(5467): Agent '%.3d' is vulnerable to '%s'. Condition: '%s'"
#define VU_PACK_VER_VULN      "(5468): The '%s' package (%s) from agent '%.3d' is vulnerable to '%s'. Condition: '%s'"
#define VU_VULN_SEND_AG       "(5469): A total of '%d' vulnerabilities have been reported for agent '%.3d'"
#define VU_FUNCTION_TIME      "(5470): It took '%ld' seconds to '%s' vulnerabilities in agent '%.3d'"
#define VU_AGENT_FINISH       "(5471): Finished vulnerability assessment for agent '%.3d'"
#define VU_END_SCAN           "(5472): Vulnerability scan finished."
#define VU_NO_SRC_VERSION     "(5480): Unable to get the source '%s' version for agent '%.3d'"
#define VU_NO_SRC_NAME        "(5481): Unable to get the source '%s' name for agent '%.3d'"
#define VU_VULN_SEND_AG_FEED  "(5482): A total of '%d' vulnerabilities have been reported for agent '%.3d' thanks to the '%s' feed."

/* File integrity monitoring debug messages */
#define FIM_DIFF_SKIPPED                    "(6200): Diff execution skipped for containing insecure characters."
#define FIM_SCHED_BATCH                     "(6201): Setting SCHED_BATCH returned: '%d'"
#define FIM_LOCAL_DIFF_DELETE               "(6202): Deleting backup '%s'. Not monitored anymore."
#define FIM_FILE_IGNORE_RESTRICT            "(6203): Ignoring file '%s' due to restriction '%s'"
#define FIM_IGNORE_ENTRY                    "(6204): Ignoring '%s' '%s' due to '%s'"
#define FIM_IGNORE_SREGEX                   "(6205): Ignoring '%s' '%s' due to sregex '%s'"
#define FIM_TAG_ADDED                       "(6206): Adding tag '%s' to directory '%s'"
#define FIM_READING_REGISTRY                "(6207): Attempt to read: '%s%s'"
#define FIM_CLIENT_CONFIGURATION            "(6208): Reading Client Configuration [%s]"
#define FIM_LOCALDIFF_DELETE                "(6209): Deleting '%s' from local hash table."
#define FIM_CANNOT_ACCESS_FILE              "(6210): Cannot access '%s': it was removed during scan."
#define FIM_SCANNING_FILE                   "(6211): File '%s'"
#define FIM_SIMBOLIC_LINK_DISABLE           "(6212): Follow symbolic links disabled."
#define FIM_CHECK_LINK_REALPATH             "(6213): Cannot get the real path of the link '%s'"
#define FIM_HASH_ADD_FAIL                   "(6214): Not enough memory to add inode to db: '%s' (%s) "
#define FIM_HASH_UPDATE                     "(6215): Updating path '%s' in inode hash table: '%s' (%s) "
#define FIM_SCANNING_IRREGFILE              "(6216): IRREG File: '%s'"
#define FIM_MAX_RECURSION_LEVEL             "(6217): Maximum level of recursion reached. Depth:%d recursion_level:%d '%s'"
#define FIM_SYMBOLIC_LINK_DISCARDED         "(6218): Discarding symbolic link '%s' is already added in the configuration."
#define FIM_SYMBOLIC_LINK_ADD               "(6219): Directory added to FIM configuration by link '%s'"
#define FIM_FILE_MSG_DELETE                 "(6220): Sending delete message for file: '%s'"
#define FIM_FREQUENCY_DIRECTORY             "(6221): Directory loaded from syscheck db: '%s'"
#define FIM_STAT_FAILED                     "(6222): Stat() function failed on: '%s' due to [(%d)-(%s)]"
#define FIM_SKIP_NFS                        "(6223): FIM skip_nfs=%d, '%s'::is_nfs=%d"
#define FIM_REALTIME_HASH_DUP               "(6224): Entry '%s' already exists in the RT hash table."
#define FIM_REALTIME_MONITORING             "(6225): The '%s' directory starts to be monitored in real-time mode."
#define FIM_REALTIME_NEWPATH                "(6226): Scanning new file '%s' with options for directory '%s'"
#define FIM_REALTIME_NEWDIRECTORY           "(6227): Directory added for real time monitoring: '%s'"
#define FIM_REALTIME_DISCARD_EVENT          "(6228): Real-time event with same checksum for file: '%s'. Ignoring it."
#define FIM_WHODATA_HANDLE_UPDATE           "(6229): The handler ('%s') will be updated."
#define FIM_WHODATA_NEWDIRECTORY            "(6230): Monitoring with Audit: '%s'"
#define FIM_WHODATA_SCAN                    "(6231): The '%s' directory has been scanned after detecting event of new files."
#define FIM_WHODATA_SCAN_ABORTED            "(6232): Scanning of the '%s' directory is aborted because something has gone wrong."
#define FIM_WHODATA_CHECKTHREAD             "(6233): Checking thread set to '%d' seconds."
#define FIM_LINK_ALREADY_ADDED              "(6234): Directory '%s' already monitored, ignoring link '%s'"
#define FIM_WHODATA_FULLQUEUE               "(6235): Real-time Whodata events queue for Windows is full. Removing the first '%d'"
#define FIM_WHODATA_EVENT_DELETED           "(6236): '%d' events have been deleted from the whodata list."
#define FIM_WHODATA_EVENTQUEUE_VALUES       "(6237): Whodata event queue values for Windows -> max_size:'%d' | max_remove:'%d' | alert_threshold:'%d'",
#define FIM_WHODATA_IGNORE                  "(6238): The file '%s' has been marked as ignored. It will be discarded."
#define FIM_WHODATA_NOT_ACTIVE              "(6239): '%s' is discarded because its monitoring is not activated."
#define FIM_WHODATA_CANCELED                "(6240): The monitoring of '%s' in whodata mode has been canceled. Added to the ignore list."
#define FIM_WHODATA_DIRECTORY_SCANNED       "(6241): The '%s' directory has been scanned. It does not need to do it again."
#define FIM_WHODATA_NEW_FILES               "(6242): New files have been detected in the '%s' directory after the last scan."
#define FIM_WHODATA_DIRECTORY_DISCARDED     "(6243): The '%s' directory has been discarded because it is not being monitored in whodata mode."
#define FIM_WHODATA_CHECK_NEW_FILES         "(6244): New files have been detected in the '%s' directory and will be scanned."
#define FIM_WHODATA_NO_NEW_FILES            "(6245): The '%s' directory has not been scanned because no new files have been detected. Mask: '%x'"
#define FIM_WHODATA_INVALID_UID             "(6246): Invalid identifier for user '%s'"
#define FIM_AUDIT_EVENT                     "(6247): audit_event: uid=%s, auid=%s, euid=%s, gid=%s, pid=%i, ppid=%i, inode=%s, path=%s, pname=%s",
#define FIM_AUDIT_EVENT1                    "(6248): audit_event_1/2: uid=%s, auid=%s, euid=%s, gid=%s, pid=%i, ppid=%i, inode=%s, path=%s, pname=%s",
#define FIM_AUDIT_EVENT2                    "(6249): audit_event_2/2: uid=%s, auid=%s, euid=%s, gid=%s, pid=%i, ppid=%i, inode=%s, path=%s, pname=%s",
#define FIM_AUDIT_DELETE_RULE               "(6250): Deleting Audit rules."
#define FIM_AUDIT_MATCH_KEY                 "(6251): Match audit_key: '%s'"
#define FIM_HEALTHCHECK_CREATE              "(6252): Whodata health-check: Detected file creation event (%s)"
#define FIM_HEALTHCHECK_DELETE              "(6253): Whodata health-check: Detected file deletion event (%s)"
#define FIM_HEALTHCHECK_UNRECOGNIZED_EVENT  "(6254): Whodata health-check: Unrecognized event (%s)"
#define FIM_HEALTHCHECK_THREAD_ACTIVE       "(6255): Whodata health-check: Reading thread active."
#define FIM_HEALTHCHECK_THREAD_FINISHED     "(6256): Whodata health-check: Reading thread finished."
#define FIM_HEALTHCHECK_CREATE_ERROR        "(6257): Whodata health-check: Failed to receive creation event."



#define FIM_HEALTHCHECK_SUCCESS             "(6261): Whodata health-check: Success."
#define FIM_HEALTHCHECK_CHECK_RULE          "(6262): Couldn't delete audit health check rule."
#define FIM_SACL_CHECK_CONFIGURE            "(6263): Setting up SACL for '%s'"
#define FIM_SACL_RESTORED                   "(6265): The SACL of '%s' has been restored correctly."
#define FIM_SACL_CONFIGURE                  "(6266): The SACL of '%s' will be configured."
#define FIM_SACL_NOT_FOUND                  "(6267): No SACL found on target. A new one will be created."
#define FIM_ELEVATE_PRIVILEGE               "(6268): The '%s' privilege has been added."
#define FIM_REDUCE_PRIVILEGE                "(6269): The '%s' privilege has been removed."
#define FIM_AUDIT_NEWRULE                   "(6270): Added audit rule for monitoring directory: '%s'"
#define FIM_AUDIT_RULEDUP                   "(6271): Audit rule for monitoring directory '%s' already added."
#define FIM_INOTIFY_ADD_WATCH               "(6272): Unable to add inotify watch to real time monitoring: '%s'. '%d' '%d':'%s'"
#define FIM_AUDIT_NOCONF                    "(6273): Cannot apply Audit config."
#define FIM_AUDIT_NORULES                   "(6274): No rules added. Audit events reader thread will not start."
#define FIM_AUDIT_RELOADING_RULES           "(6275): Reloading Audit rules."
#define FIM_AUDIT_RELOADED_RULES            "(6276): Audit rules reloaded. Rules loaded: %i"
#define FIM_AUDIT_THREAD_STOPED             "(6277): Audit thread finished."
#define FIM_AUDIT_HEALTHCHECK_RULE          "(6278): Couldn't add audit health check rule."
#define FIM_AUDIT_HEALTHCHECK_START         "(6279): Whodata health-check: Starting."
#define FIM_AUDIT_HEALTHCHECK_FILE          "(6280): Couldn't create audit health check file."
#define FIM_SYSCOM_ARGUMENTS                "(6281): SYSCOM %s needs arguments."
#define FIM_SYSCOM_UNRECOGNIZED_COMMAND     "(6282): SYSCOM Unrecognized command '%s'"
#define FIM_SYSCOM_FAIL_GETCONFIG           "(6283): At SYSCOM getconfig: Could not get '%s' section."
#define FIM_SYSCOM_REQUEST_READY            "(6284): Local requests thread ready."
#define FIM_SYSCOM_EMPTY_MESSAGE            "(6285): Empty message from local client."
#define FIM_SYSCOM_THREAD_FINISED           "(6286): Local server thread finished."
#define FIM_CONFIGURATION_FILE              "(6287): Reading configuration file: '%s'"
#define FIM_SCAL_NOREFRESH                  "(6288): Could not refresh the SACL of '%s'. Its event will not be reported."
#define FIM_DISCARD_RECYCLEBIN              "(6289): File '%s' is in the recycle bin. It will be discarded."
#define FIM_REALTIME_ADD                    "(6290): Unable to add directory to real time monitoring: '%s'"
#define FIM_WHODATA_REPLACELINK             "(6291): Replacing the symbolic link: '%s' -> '%s'"
#define FIM_WHODATA_FILENOEXIST             "(6292): The '%s' file does not exist, but this will be notified when the corresponding event is received."
#define FIM_LINKCHECK_TIME                  "(6293): Configured symbolic links will be checked every %d seconds."
#define FIM_LINKCHECK_CHANGE                "(6294): Configured symbolic links will be checked every %d seconds."
#define FIM_LINKCHECK_NOCHANGE              "(6295): The symbolic link of '%s' has not changed."
#define FIM_LINKCHECK_FINALIZE              "(6296): Links check finalized."
#define FIM_LINKCHECK_FILE                  "(6297): File '%s' was inside the unlinked directory '%s'. It will be notified."
#define FIM_WHODATA_REMOVE_FOLDEREVENT      "(6298): Removed folder event received for '%s'"
#define FIM_WHODATA_UNCONTROLLED_EVENT      "(6299): Uncontrolled whodata event on '%s'"
#define FIM_WHODATA_DIRECTORY_REMOVED       "(6300): Directory '%s' has been moved or removed."
#define FIM_WHODATA_UNCONTROLLED_REMOVE     "(6301): Uncontrolled removed folder event."
#define FIM_WHODATA_IGNORE_EVENT            "(6302): Ignoring removing event for '%s' directory."
#define FIM_WHODATA_DEVICE_LETTER           "(6303): Device '%s' associated with the mounting point '%s'"
#define FIM_WHODATA_DEVICE_PATH             "(6304): Find device '%s' in path '%s'"
#define FIM_WHODATA_DEVICE_REPLACE          "(6305): Replacing '%s' to '%s'"
#define FIM_WHODATA_PATH_NOPROCCESED        "(6306): The path could not be processed in Whodata mode. Error: %u"
#define FIM_WHODATA_CONVERT_PATH            "(6307): Convert '%s' to '%s' to process the whodata event."
#define FIM_WHODATA_FOLDER_REMOVED          "(6308): File '%s' was inside the removed directory '%s'. It will be notified."
#define FIM_WHODATA_IGNORE_FILEEVENT        "(6309): Ignoring remove event for file '%s' because it has already been reported."
#define FIM_CHECKSUM_MSG                    "(6310): Sending msg to the server: %s"
#define FIM_PATH_EXEED_MAX                  "(6311): The path exeed maximum permited (%d): '%s'"
#define FIM_DBSYNC_NO_ARGUMENT              "(6312): Data synchronization command '%s' with no argument."
#define FIM_DBSYNC_UNKNOWN_CMD              "(6313): Unknown data synchronization command: '%s'"
#define FIM_DBSYNC_INVALID_ARGUMENT         "(6314): Invalid data synchronization argument: '%s'"
#define FIM_DBSYNC_DEC_ID                   "(6315): Setting global ID back to lower message ID (%ld)"
#define FIM_DBSYNC_DROP_MESSAGE             "(6316): Dropping message with id (%ld) greater than global id (%ld)"
#define FIM_DBSYNC_SEND                     "(6317): Sending integrity control message: %s"
#define FIM_MONITORING_FILES_COUNT          "(6318): Number of indexed files %s scanning: %u"
#define FIM_CONFIGURATION_NOTFOUND          "(6319): No configuration found for (%s):'%s'"
#define FIM_PROCESS_PRIORITY                "(6320): Setting process priority to: '%d'"
#define FIM_SEND                            "(6321): Sending FIM event: %s"
#define FIM_AUDIT_RELOADED                  "(6322): Reloaded audit rule for monitoring directory: '%s'"
#define FIM_REALTIME_DIRECTORYCHANGES       "(6323): Unable to set 'ReadDirectoryChangesW' for directory: '%s'"
#define FIM_HASHES_FAIL                     "(6324): Couldn't generate hashes for '%s'"
#define FIM_EXTRACT_PERM_FAIL               "(6325): It was not possible to extract the permissions of '%s'. Error: %d"
#define FIM_RBTREE_DUPLICATE_INSERT         "(6326): Couldn't insert entry, duplicate path: '%s'"
#define FIM_HASH_INSERT_INODE_HASH          "(6327): Unable to add inode to db: '%s' => '%s'"
#define FIM_RBTREE_REPLACE                  "(6328): Unable to update file to db, key not found: '%s'"
#define FIM_REGISTRY_EVENT_FAIL             "(6329): Unable to save registry key: '%s'"
#define FIM_RUNNING_SCAN                    "(6330): The scan has been running during: %.3f sec (%.3f clock sec)"
#define FIM_GET_ATTRIBUTES                  "(6331): Couldn't get attributes for file: '%s'"
#define FIM_WARN_REALTIME_UNSUPPORTED       "(6332): The realtime monitoring request on unsupported system."
#define FIM_WARN_WHODATA_UNSUPPORTED        "(6333): The who-data monitoring request on unsupported system."
#define FIM_AUDIT_INVALID_AUID              "(6334): Audit: Invalid 'auid' value read. Check Audit configuration (PAM)."
#define FIM_ENTRIES_INFO                    "(6335): Fim entries: %d"
#define FIM_INODES_INFO                     "(6336): Fim inode entries: %d, path count: %d"
#define FIM_WHODATA_INVALID_UNKNOWN_UID     "(6337): The user ID could not be extracted from the event."
#define FIM_EMPTY_DIRECTORIES_CONFIG        "(6338): Empty directories tag found in the configuration."
#define FIM_DELETE_EVENT_PATH_NOCONF        "(6339): Delete event from path without configuration: '%s'"
#define FIM_DELETE_DB_TRY                   "(6340): Failed to delete FIM database '%s'- %dº try."
#define FIM_DELETE_DB                       "(6341): Failed to delete FIM database '%s'."
#define FIM_FILE_LIMIT_VALUE                "(6342): Maximum number of files to be monitored: '%u'"
#define FIM_FILE_LIMIT_UNLIMITED            "(6343): No limit set to maximum number of files to be monitored"
#define FIM_INOTIFY_WATCH_DELETED           "(6344): Inotify watch deleted for '%s'"
#define FIM_NUM_WATCHES                     "(6345): Folders monitored with real-time engine: %u"
#define FIM_REALTIME_CALLBACK               "(6346): Realtime watch deleted for '%s'"

/* wazuh-logtest debug messages*/
#define LOGTEST_INV_NUM_THREADS             "(7000): Number of logtest threads too high. Only creates %d threads"
#define LOGTEST_INV_NUM_USERS               "(7001): Number of maximum users connected in logtest too high. Only allows %d users"
#define LOGTEST_INV_NUM_TIMEOUT             "(7002): Number of maximum user timeouts in logtest too high. Only allows %ds maximum timeouts"

#endif /* DEBUG_MESSAGES_H */
