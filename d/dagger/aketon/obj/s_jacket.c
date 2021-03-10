#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

int flag;

void create() {
   ::create();
   set_name("silk jacket");
   set_id( ({"silk jacket","jacket"}) );
   set("short","Silk jacket");  
   set("long","This is a finely made, expensive silk jacket.");
   set_type("clothing");
   set_limbs( ({"torso"}) );
   set_weight(1);
   set_value(120);
   flag = 1;
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
