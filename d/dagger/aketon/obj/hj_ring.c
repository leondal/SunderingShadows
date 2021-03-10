#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

create() {
   ::create();
   set_name("heavily jeweled ring");
   set_id( ({"ring","heavily jeweled ring"}) );
   set("short","heavily jeweled ring");
   set("long","This ring is heavily jeweled.\n");
   set_type("ring");
   set_ac(0);
   set_limbs( ({"right hand"}) );
   set_weight(2);
   set("value",100);
   set_wear( (: TO,"wear_func" :) );
   set_remove( (: TO,"remove_func" :) );
}

int wear_func(string str) {
   object *stuff;
   int i,j,flag;
   stuff = TP->all_armour();
   j = sizeof(stuff);
   for(i = 0;i < j;i++) {
      if( (string)stuff[i]->query_type() == "ring" &&
         (string)stuff[i]->query_name() == "heavily jeweled ring" ) {
         flag = 1;
         break;
      }
   }
   if(flag) {
      write("Wear only one at a time please.");
      return 0;
   }
   if(ETO == TP && (string)TP->query_race() == "elf") {
      write("You feel more charming.");
      TP->add_stat_bonus("charisma",2);
      return 1;
   }
   else if(ETO == TP && (string)TP->query_race() == "half-elf") {
      write("You feel more charming.");
      TP->add_stat_bonus("charisma",1);
      return 1;
   }
   return 1;
}

int remove_func(string str) {
   if(ETO == TP && (string)TP->query_race() == "elf") {
      write("You feel less charming.");
      TP->add_stat_bonus("charisma",-2);
   }
   else if(ETO == TP && (string)TP->query_race() == "half-elf") {
      write("You feel less charming.");
      TP->add_stat_bonus("charisma",-1);
   }
   return 1;
}
