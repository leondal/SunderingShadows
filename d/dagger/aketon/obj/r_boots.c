#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

int flag;

void create() {
   ::create();
   set_name("riding boots");
   set_id( ({"riding boots","boots"}) );
   set("short","Riding boots");
   set("long","This is a pair of riding boots.");
   set_type("clothing");
   set_limbs( ({"right foot", "left foot"}) );
   set_weight(2);
   set_value(10);
   flag = 0;
}

void init() {
   ::init();
   if(flag)
      return;
   if(ETO == TP || (string)TP->query_race() == "elf") {
      if( !random(50) )
         set_ac(1);
      else if( !random(100) )
         set_ac(2);
      else if( !random(200) )
         set_ac(3);
      flag = 1;
   }
}
