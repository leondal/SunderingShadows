//      /bin/user/_deaths.c
//      gives a player's describe
// Created by Garrett for Crystal.
#include <daemons.h>

#include <std.h>

inherit DAEMON;

int cmd_getdesc(string str) {
    string borg, tmp;
//    string *lines,*test;
    object ob;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    ob=find_player(lower_case(str));
    if (!objectp(ob))
     {
      if (!user_exists(lower_case(str)))
       return notify_fail("Suck, no player like that connected.\n");
     else
    borg=USERCALL->user_call(str,"query_desc");
  }
  else
    borg=ob->query_desc();


    this_player()->more(explode(borg, "\n"));
    return 1;
}

void help() {
   write(@FNORD
This command will return the description of a player who 
is online.
FNORD
);
}
