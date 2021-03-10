//Octothorpe (2/8/09)
//Underdark Mining Caverns Kobold Cavern Room Delta 4

#include <std.h>
#include "../defs.h"
inherit INH+"kobcavern2";

void create(){
   ::create();
   set_exits(([
      "northeast":RMS"kobcavernc5",
      "northwest":RMS"kobcavernc3",
   ]));
}