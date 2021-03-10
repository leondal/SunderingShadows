#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

int flag;

create() {
   ::create();
   set_name("slight gold band");
   set_id( ({"ring","gold band"}) );
   set("short","slight gold band");
   set("long","This is a small gold band.\n");
   set_type("ring");
   set_ac(0);
   set_limbs( ({"right hand"}) );
   set_weight(2);
   set("value",100);
   set_wear( (: TO,"wear_func" :) );
   flag = 0;
}

void init() {
   ::init();
   if(flag)
      return;
   if(ETO == TP && (string)TP->query_race() == "elf") {
      if( !random(20) )
         set_ac(1);
      flag = 1;
   }
}

int wear_func(string str) {
   object *stuff;
   int i,j,flag1;
   stuff = TP->all_armour();
   j = sizeof(stuff);
   for(i = 0;i < j;i++) {
      if( (string)stuff[i]->query_type() == "ring" &&
         (string)stuff[i]->query_name() == "slight gold band" ) {
         flag1 = 1;
         break;
      }
   }
   if(flag1) {
      write("Wear only one at a time please.");
      return 0;
   }
   return 1;
}
