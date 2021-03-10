//      Cancelend command for use with Shutdown Daemon v2.0
//      Thorn@Shadowgate
//      10/5/94 (v1.1 960517)
//      adm commands
//      _cancelend

#include <std.h>
#include <security.h>
#include <objects.h>
#include <rooms.h>
#include <daemons.h>

inherit DAEMON;

int cmd_cancelend(string str) {
    object ob;
//    if(!archp(previous_object())) return 0;
        if(this_player()->query_forced()) return 0;
    seteuid(UID_SHUTDOWN);
    catch(call_other(SHUT_D, "cancelShutdown"));
    catch(call_other(SHUT_D, "checkMemory"));
    seteuid(getuid());
    write("Ok.\n");
    return 1;
}

int help() {
    write( @EndText
Syntax: cancelend

Effect: Stops the shutdown process initiated by the <end> command.

See also: shutdown, end
EndText
    );
    return 1;
}
