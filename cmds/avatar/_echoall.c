//      /bin/dev/_echoall.c
//      from the Nightmare Mudlib
//      echos to everyone on the mud
//      created by ????

#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_echoall(string str) {

   string posxxx;
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if(!str) {
        notify_fail("Echoall what?\n");
        return 0;
    }
  str = replace_string(str,"%^NL%^","\n");
    message("echo", str, users());
    seteuid(UID_LOG);
    seteuid(getuid());
    return 1;
}

void help() {
    message("help",
      "Syntax: <echoall [message]>\n\n"
      "Sends the message to all users in the game.  Abuse of this "
      "power can result in serious action from law.", this_player()
    );
}
