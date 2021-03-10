//      /bin/adm/_broadcast.c
//      from the Nightmare mudlib
//      like shout, except that it overrides ALL blocking
//      created by Descartes of Borg 930823

#include <std.h>

inherit DAEMON;

int cmd_broadcast(string str) {

    if(!archp(previous_object())) return 0;
    message("broadcast", sprintf("Broadcast message from %s: %s",
      (string)this_player()->query_cap_name(), str), users());
    return 1;
}

void help() {
    message("help",
      "Syntax: <broadcast [message]>\n\n"
      "Sends out a message that is in English and immune to all forms of "
      "blocking.  Do not use this for shout matches!", this_player()
    );
}
