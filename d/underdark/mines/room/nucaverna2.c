//Octothorpe (8/7/08)
//Underdark Mining Caverns Neutral Cavern Room Alpha 2

#include <std.h>
#include "../defs.h"
inherit INH+"nucavern";

void create(){
   ::create();
   set_exits(([
      "north":RMS"fissure",
      "southeast":RMS"nucavernb3",      
      "south":RMS"nucavernb2",
      "southwest":RMS"nucavernb1",
      "west":RMS"nucaverna1",
   ]));
}