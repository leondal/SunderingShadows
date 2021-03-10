//Octothorpe (2/2/09)
//Underdark Mining Caverns, Neutral Cavern Spawn Room Inherit

#include <std.h>
#include "../defs.h"
inherit INH+"nucavern";

int active;

void create(){
   switch(random(20)){
      case 0..17: set_monsters(({MON"hookgrunt"}),({1+random(1)})); break;
      case 18: set_monsters(({MON"floele"}),({1+random(2)})); break;
      case 19: set_monsters(({MON"earthelement"}),({1})); break;
      default: break;
   }
   ::create();
   set_repop(50);
}

void reset(){
   active = has_mobs();
   if(!active){
     if(mons) mons = ([]);
   switch(random(20)){
      case 0..17: set_monsters(({MON"hookgrunt"}),({1+random(1)})); break;
      case 18: set_monsters(({MON"floele"}),({1+random(2)})); break;
      case 19: set_monsters(({MON"earthelement"}),({1})); break;
      default: break;
      }
   }
   ::reset();
}