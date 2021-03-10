//Octothorpe (2/2/09)
//Underdark Mining Caverns, Svirfneblin Cavern Spawn Room Inherit

#include <std.h>
#include "../defs.h"
inherit INH+"gnocavern";

int active;

void create(){
   switch(random(20)){
      case 0..8: set_monsters(({MON"gnominer"}),({1+random(2)})); break;
      case 9..17: set_monsters(({MON"gnowarr"}),({1+random(2)})); break;
      case 18..19: set_monsters(({MON"gnopriest"}),({1})); break;
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
      case 0..8: set_monsters(({MON"gnominer"}),({1+random(2)})); break;
      case 9..17: set_monsters(({MON"gnowarr"}),({1+random(2)})); break;
      case 18..19: set_monsters(({MON"gnopriest"}),({1})); break;
      default: break;
      }
   }
   ::reset();
}