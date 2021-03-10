//Octothorpe (2/8/09)
//Underdark Mining Caverns Kobold Cavern Room Bravo 4

#include <std.h>
#include "../defs.h"
inherit INH+"kobcavern2";

void create(){
   ::create();
   set_exits(([
      "west":RMS"kobcavernb3",
      "southeast":RMS"kobcavernc5",
   ]));
}