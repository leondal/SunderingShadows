//  "End" Command for ShadowGate, to run with Shutdown Daemon v2.0
//  Thorn@ShadowGate
//  960517
//  (based on the admin command to load armageddon
//  created by Descartes of Borg from the Nightmare mudlib)
//  /cmds/adm/_reboot.c

#include <std.h>
#include <security.h>
#include <objects.h>
#include <rooms.h>
#include <daemons.h>

inherit DAEMON;

int cmd_reboot(string str) {
    object ob;
    int ShutdownTime;

//   if( (string)PO->query_position() != "overseer" || (string)PO->query_position() != "developer") return 0;
    if(this_player()->query_forced()) return 0;
    seteuid(UID_SHUTDOWN);
    if(str == "now") 
      catch(call_other(SHUT_D, "startShutdown",6,00));
    else
      return 0;
    seteuid(getuid());
    write("Ok.\n");
    log_file("game_log", "Emergency Shutdown initiated by "+
            (this_player()->query_name())+": "+ctime(time())+"\n");
    return 1;
}

int help() {

    write( @EndText
Syntax: end [time in minutes]

Effect: Starts the timed reboot process.  This is the normal way to shutdown
the MUD because it gives players plenty of notice and safely saves and quits
players before it takes down the MUD.

See also: shutdown
EndText
    );
    return 1;
}
