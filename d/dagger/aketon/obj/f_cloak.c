#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

int flag;

void create() {
   ::create();
   set_name("fur cloak");
   set_id( ({"fur cloak","cloak"}) );
   set("short","Fur cloak");
   set("long","This is a fine fur cloak.");
   set_weight(3);
   set_type("clothing");
   set_limbs( ({"neck"}) );
   set_value(50);
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
