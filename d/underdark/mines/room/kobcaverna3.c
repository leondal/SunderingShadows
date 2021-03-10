//Octothorpe (2/8/09)
//Underdark Mining Caverns Kobold Cavern Room Alpha 3

#include <std.h>
#include "../defs.h"
inherit INH+"kobcavern2";

void create(){
   ::create();
   set_exits(([
      "south":RMS"kobcavernb3",
   ]));
}