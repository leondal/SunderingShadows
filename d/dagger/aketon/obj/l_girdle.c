#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

int flag;

void create() {
   ::create();
   set_name("leather girdle");
   set_id( ({"leather girdle","girdle"}) );
   set("short","Leather girdle");
   set("long","This is a leather girdle.");
   set_type("clothing");
   set_limbs( ({"torso"}) );
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
