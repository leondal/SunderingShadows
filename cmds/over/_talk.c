#include <std.h>
#include "/realms/grendel/grendel.h"

inherit DAEMON;

int cmd_talk(string str){
   object who;
   string race;

   if(!str){
      TP->set_spoken("common");
      return 1;
   }
   who = find_player(str);
   if(!objectp(who)){
      return notify_fail("You can't find that person to talk to.\n");
   }
   race = who->query_race();
    TP->set_spoken(query_base_race_lang(race));
   tell_object(TP,"You are now speaking "+TP->query_spoken()+".");
   return 1;
}

