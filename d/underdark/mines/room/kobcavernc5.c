//Octothorpe (2/8/09)
//Underdark Mining Caverns Kobold Cavern Room Charlie 5

#include <std.h>
#include "../defs.h"
inherit INH+"kobcavern2";

void create(){
   ::create();
   set_exits(([
      "northwest":RMS"kobcavernb4",
      "southwest":RMS"kobcavernd4",
   ]));
}