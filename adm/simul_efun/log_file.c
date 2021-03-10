#include <dirs.h>
#include <security.h>
#include <objects.h>
#include <conf.h>

/**
 * @file
 */

/**
 * Writes message to a logfile
 *
 * @param fl Logfile name in logs directory you're going to write to
 * @param msg Message
 * @param continous Wheter to store all previvous versions of log or not
 */
varargs void log_file(string fl, string msg, int continous)
{
    if (!stringp(fl)) {
        error("Bad argument 1 to log_file().\n");
    }
    if (!stringp(msg)) {
        msg = identify(msg);
    }
    if (strsrch(fl, "..") != -1) {
        error("Illegal file reference.\n");
    }
    seteuid(UID_ROOT);
    if (file_size(fl = sprintf("%s/%s", DIR_LOGS, fl)) > MAX_LOG_SIZE) {
        if (continous) {
            rename(fl, sprintf("%s." + time(), fl));
        } else {
            rename(fl, sprintf("%s.old", fl));
        }
    }
    msg = ctime(time()) + " : " + msg;
    write_file(fl, msg);
    seteuid(UID_MUDLIB);
}
