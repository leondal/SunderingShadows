#ifndef __SECURITY_H
#define __SECURITY_H

/*  Mud euid divisions (set based on uid) */

#define UID_ROOT "Root"
#define UID_SYSTEM "System"
#define UID_BACKBONE "Backbone"
#define UID_MUDLIB "Mudlibrary"

/* Special euid groups (set at time of special use, then returned to uid) */

#define UID_BANISH "Banish"
#define UID_POSTAL "Postal"
#define UID_BBOARD "Bboard"
#define UID_SOCKET "Socket"
#define UID_DESTRUCT "Destruct"
#define UID_EXEC "Exec"
#define UID_SAVEACCESS "SaveAccess"
#define UID_LOG "Log"
#define UID_ADVANCE "Advance"
#define UID_SNOOP "Snoop"
#define UID_USERACCESS "UserAccess"
#define UID_FORCE "Force"
#define UID_RESTORE "Restore"
#define UID_HM "HighMortal"
#define UID_SHUTDOWN "Shutdown"
#define UID_LAW "UidLaw"
#define UID_LAWP ({"tsera", "yves", "tlaloc", "kismet", "chernobog"})
#define UID_APPROVAL "Approval"
#define UID_GOD "tlaloc"

/* Generalized euid groupings (set at time of special use, return to uid) */

#define UID_POSTALSAVE "PostalSave"
#define UID_DAEMONSAVE "DaemonSave"
#define UID_SECURE_DAEMONSAVE "SecureDaemonSave"
#define UID_VOTESAVE              "VoteSave"
#define UID_ARCHSAVE              "ArchSave"
#define UID_CRESAVE               "CreSave"
#define UID_USERSAVE              "UserSave"
#define UID_AREA_DB             "dbuid"


#define ICQ ({"ICQ","icq"," ICQ"," icq","i c q","i.c.q"})
#endif /* __SECURITY_H */
