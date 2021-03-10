#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

int flag;

void create() {
   ::create();
   set_name("embroidered robe");
   set_id( ({"embroidered robe","robe"}) );
   set("short","Embroidered robe");
   set("long","This is a finely embroidered robe.");
   set_weight(2);
   set_type("clothing");
   set_limbs("torso");
   set_value(20);
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
