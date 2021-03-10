//Octothorpe (8/7/08)
//Underdark Mining Caverns Neutral Cavern Room Bravo 3

#include <std.h>
#include "../defs.h"
inherit INH+"nucavern2";

void create(){
   ::create();
   set_exits(([
      "southwest":RMS"nucavernc2",
      "west":RMS"nucavernb2",
      "northwest":RMS"nucaverna2",
      "northeast":RMS"nucaverna4",
   ]));
}