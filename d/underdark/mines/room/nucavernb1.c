//Octothorpe (8/7/08)
//Underdark Mining Caverns Neutral Cavern Room Bravo 1

#include <std.h>
#include "../defs.h"
inherit INH+"nucavern";

void create(){
   ::create();
   set_exits(([
      "north":RMS"nucaverna1",
      "northeast":RMS"nucaverna2",      
      "east":RMS"nucavernb2",
      "southeast":RMS"nucavernc2",
      "south":RMS"nucavernc1",
   ]));
}