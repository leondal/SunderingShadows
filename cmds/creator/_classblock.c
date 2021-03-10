//  _classblock.c Created by Hanse@Nightmare and Screwit 3/5/93
//  It allows a wizard to tune in or out all the class lines with one command
// added cavalier and antipaladin & restricted builders & apprentices from using it *Styx*  4/10/03

#include <daemons.h>
#include <std.h>

inherit DAEMON;
 
void help();

int cmd_classblock(string str) {
   string *list;
   int i;
   object tp;
 
   if(!str || (str != "on" && str != "off") ) {
      help();
      return 1;
   }
   if((string)TP->query_position() == "builder" || (string)TP->query_position() == "apprentice")
      return notify_fail("Sorry, you don't have access to class channels.\n");

   tp=this_player();
  list= ({"fighter", "paladin", "ranger", "thief", "bard", "cleric", "druid", "mage", "cavalier", "antipaladin"});
    for(i=0;i<8;i++)
      if(str == "off" && tp->query_blocked(list[i]) )
         tp->set_blocked(list[i]);
      else if(str == "on" && !tp->query_blocked(list[i]) )
         tp->set_blocked(list[i]);
   write("Classblock: "+str+"\n");
   return 1;
}
 
void help() {
    write(@END
Syntax: <classblock (on/off)>
 
This command turns on all class lines or off all class lines.
END
);
}
