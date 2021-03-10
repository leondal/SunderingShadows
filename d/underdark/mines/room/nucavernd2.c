//Octothorpe (8/7/08)
//Underdark Mining Caverns Neutral Cavern Room Delta 2

#include <std.h>
#include "../defs.h"
inherit INH+"nucavern2";

void create(){
   ::create();
   set_exits(([
      "north":RMS"nucavernc2",
      "southwest":RMS"nucaverne1",
      "northwest":RMS"nucavernc1",
   ]));
}