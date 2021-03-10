//Octothorpe (2/8/09)
//Underdark Mining Caverns Kobold Cavern Room Bravo 3

#include <std.h>
#include "../defs.h"
inherit INH+"kobcavern";

void create(){
   ::create();
   set_exits(([
      "north":RMS"kobcaverna3",
      "east":RMS"kobcavernb4",
      "west":RMS"kobcavernb2",
   ]));
}