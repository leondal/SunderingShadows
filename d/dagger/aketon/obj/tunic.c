#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

int flag;

void create() {
   ::create();
   set_name("tunic");
   set_id( ({"tunic","shirt"}) );
   set("short","Tunic");
   set("long","This is a tunic.");
   set_type("clothing");
   set_limbs( ({"torso"}) );
   set_weight(2);
   set_value(30);
   flag = 0;
}

void init() {
   ::init();
   if(flag)
      return;
   if(ETO == TP || (string)TP->query_race() == "elf") {
      if( !random(100) )
         set_ac(1);
      else if( !random(200) )
         set_ac(2);
      else if( !random(300) )
         set_ac(3);
      flag = 1;
   }
}
