//Octothorpe (2/8/09)
//Underdark Mining Caverns, Kobold Cavern Spawn Room Inherit

#include <std.h>
#include "../defs.h"
inherit INH+"kobcavern";

int active;

void create(){
   switch(random(20)){
      case 0..17: set_monsters(({MON"koboldbasic"}),({3+random(2)})); break;
      case 18..19: set_monsters(({MON"kobchamp"}),({1})); break;
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
      case 0..17: set_monsters(({MON"koboldbasic"}),({3+random(2)})); break;
      case 18..19: set_monsters(({MON"kobchamp"}),({1})); break;
      default: break;
      }
   }
   ::reset();
}