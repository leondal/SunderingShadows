#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

int flag;

void create() {
   ::create();
   set_name("leather gloves");
   set_id( ({"gloves","gauntlets","glove","gauntlet"}) );
   set("short","Leather gloves");
   set("long","This is a pair of leather gloves.");
   set_type("clothing");
   set_limbs( ({"right hand","left hand"}) );
   set_weight(1);
   set_value(20);
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
