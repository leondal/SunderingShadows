//Octothorpe (2/8/09)
//Underdark Mining Caverns Kobold Cavern Room Bravo 2

#include <std.h>
#include "../defs.h"
inherit INH+"kobcavern2";

void create(){
   ::create();
   set_exits(([
      "southwest":RMS"kobcavernc1",
      "south":RMS"kobcavernc2",
      "east":RMS"kobcavernb3",
   ]));
}