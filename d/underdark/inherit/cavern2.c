#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){
   switch(random(20)) {
      case 0..1: set_monsters(({MIDMON"cat"}),({1})); break;
      case 2..3: set_monsters(({MIDMON"piercer"}),({4+random(2)})); break;
      case 4..6: set_monsters(({MIDMON"troll",MIDMON"troll2"}),({2,1})); break;
      case 7..9: set_monsters(({MIDMON"illithid"}),({1})); break;
      case 10..11: set_monsters(({MIDMON"grellworker",MIDMON"grellphil"}),({2+random(2),1})); break;
      case 12..13: set_monsters(({MIDMON"gnomewarr",MIDMON"gnomepriest",MIDMON"elemental"}),({1,1,1})); break;
      case 14..16: set_monsters(({MIDMON"ravener",MIDMON"ravener2"}),({3+random(3),1})); break;
      case 17: set_monsters(({MIDMON"cube"}),({1})); break;
      case 18..19: set_monsters(({MIDMON"hydra"}),({1})); break;
      default:  break;
   }
   ::create();
   set_repop(45);
}

void reset() {
   int active;
   active = has_mobs();
   /* if(!active) { */
      if(mons)  mons = ([]);
      switch(random(20)) {
        case 0..1: set_monsters(({MIDMON"cat"}),({1})); break;
        case 2..3: set_monsters(({MIDMON"piercer"}),({4+random(2)})); break;
        case 4..6: set_monsters(({MIDMON"troll",MIDMON"troll2"}),({2,1})); break;
        case 7..9: set_monsters(({MIDMON"illithid"}),({1})); break;
        case 10..11: set_monsters(({MIDMON"grellworker",MIDMON"grellphil"}),({2+random(2),1})); break;
        case 12..13: set_monsters(({MIDMON"gnomewarr",MIDMON"gnomepriest",MIDMON"elemental"}),({1,1,1})); break;
        case 14..16: set_monsters(({MIDMON"ravener",MIDMON"ravener2"}),({3+random(3),1})); break;
        case 17: set_monsters(({MIDMON"cube"}),({1})); break;
        case 18..19: set_monsters(({MIDMON"hydra"}),({1})); break;
        default:  break;
     }
   /* } */
   ::reset();
}
