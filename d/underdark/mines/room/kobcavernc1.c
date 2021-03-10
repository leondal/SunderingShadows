//Octothorpe (2/8/09)
//Underdark Mining Caverns Kobold Cavern Room Charlie 1

#include <std.h>
#include "../defs.h"
inherit INH+"kobcavern2";

void create(){
   ::create();
   set_exits(([
      "northeast":RMS"kobcavernb2",
      "east":RMS"kobcavernc2",
   ]));
}