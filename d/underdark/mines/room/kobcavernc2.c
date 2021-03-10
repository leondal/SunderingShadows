//Octothorpe (2/8/09)
//Underdark Mining Caverns Kobold Cavern Room Charlie 2

#include <std.h>
#include "../defs.h"
inherit INH+"kobcavern";

void create(){
   ::create();
   set_exits(([
      "north":RMS"kobcavernb2",
      "south":RMS"kobcavernd2",
      "west":RMS"kobcavernc1",
   ]));
}