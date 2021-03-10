//Octothorpe (8/7/08)
//Underdark Mining Caverns Neutral Cavern Room Alpha 1

#include <std.h>
#include "../defs.h"
inherit INH+"nucavern2";

void create(){
   ::create();
   set_exits(([
      "east":RMS"nucaverna2",
      "southeast":RMS"nucavernb2",      
      "south":RMS"nucavernb1",
      
   ]));
}