// new command to list current mounts.
#include <std.h>
inherit DAEMON;

int cmd_horses(string str) {
   string *mypets, file, holder, myname;
   int i;

   if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if (sizeof((object *)TP->query_attackers())) return notify_fail("You're too busy to do that!\n");

   if(str) return notify_fail("Syntax: <horses>.\n");
   mypets = TP->query_pets();
   if(!sizeof(mypets)) {
     tell_object(TP,"You don't own any mounts!");
     return 1;
   }
   tell_object(TP,"%^YELLOW%^You own the following pets...%^RESET%^\n");

   holder = "";
   for(i=0;i<sizeof(mypets);i++) {
     if(strsrch(mypets[i],".c") != -1) file = mypets[i];
     else file = mypets[i]+".c";
     if(!file_exists(file)) continue;
     myname = file->query_short();
     holder += myname+"%^RESET%^\n";
   }
   tell_object(TP,holder);
   return 1;
}