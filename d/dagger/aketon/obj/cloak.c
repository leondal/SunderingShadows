#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

int flag;

void create() {
   ::create();
   set_name("cloak");
   set_id( ({"cloak","cloak of good cloth"}) );
   set("short","Cloak");
   set("long","This is a cloak of good cloth.");
   set_weight(2);
   set_type("clothing");
   set_limbs( ({"neck"}) );
   set_value(10);
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
