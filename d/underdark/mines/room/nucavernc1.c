//Octothorpe (8/7/08)
//Underdark Mining Caverns Neutral Cavern Room Charlie 1

#include <std.h>
#include "../defs.h"
inherit INH+"nucavern2";

void create(){
   ::create();
   set_exits(([
      "north":RMS"nucavernb1",
      "northeast":RMS"nucavernb2",
      "east":RMS"nucavernc2",
      "southeast":RMS"nucavernd2",
   ]));
}