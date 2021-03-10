#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

create() {
   ::create();
   set_name("diamond engagement ring");
   set_id( ({"ring","diamond engagement ring"}) );
   set("short","diamond engagement ring");
   set("long","This is a diamond engagement ring.\n");
   set_type("ring");
   set_ac(0);
   set_limbs( ({"left hand"}) );
   set_weight(2);
   set("value",200);
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
         (string)stuff[i]->query_name() == "diamond engagement ring" ) {
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
