#include <std.h>

inherit DAEMON;

int cmd_hppreview(string str){

   object who;
   int i,j;
   string *classes;
   int hp=20;

   if (!str) {
      return notify_fail("hppreview <name>");

   }

   who = find_player(str);

   if (!objectp(who)) {
      return notify_fail("That player isn't online.");
   }
    if (avatarp(who)) {
        write("That would be useless!");
        return 1;
    }

   classes = who->query_classes();

   for (i= 0;i< sizeof(classes);i++) {
      write("For class "+classes[i]);
      for (j=1;j<=who->query_class_level(classes[i]);j++) {
//         write("For the level "+j);
hp += "/adm/daemon/advance_d"->get_hp_bonus(classes[i],who->query_base_stats("constitution"),j,who);
      }
   }
   

   write("New hp for "+str+" are "+hp);
   write("Change in HP is:"+(hp-(int)who->query_max_hp())+".");
   return 1;

}
