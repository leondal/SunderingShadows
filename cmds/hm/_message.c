//	/bin/high_mortal/_message.c
//	from the Nightmare mudlib
//	movement message changing
//	created by Descartes of Borg 09 december 1992

#include <std.h>

inherit DAEMON;

int cmd_message(string str) {
    string what, msg;

    if(!str) {
	notify_fail("Which message? What is the message?\n");
	return 0;
    }
    if(sscanf(str, "%s %s", what, msg) != 2) {
	notify_fail("Correct syntax: <message [in | out] [msg]>\n");
	return 0;
    }
    if(what != "in" && what != "out") {
	notify_fail("You may only set your messages in and out.\n");
	return 0;
    }
    if(what == "in") this_player()->setenv("MIN", "$N "+msg);
   else if(strsrch(msg,"$D") != -1) {
      TP->setenv("MOUT","$N "+msg+"");
      return 1;
   }
   else TP->setenv("MOUT","$N "+msg+" $D");
   return 1;
}

void help() {
    write("Syntax: <message [in | out] [msg]>\n\n"+
   "Changes your messages when you enter and exit a room.\n"+
	"The in message makes other players see :\n"+
	"    Your_name msg. when you enter a room, whereas the out:\n"+
   "    Your_name msg direction. when you leave.\n"+
   "If you wish to have the direction in a spot other than the end, you may place"+
   " a $D in the msg where you would like it to go instead, otherwise it will"+
   " default to being at the end. Example:\n"+
   "    <message out> walks $D with a swagger.\n"+
   "    Others would see: Yourname walks direction with a swagger.\n\n"+
   "See also: review\n");
}
