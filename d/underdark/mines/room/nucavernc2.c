//Octothorpe (8/7/08)
//Underdark Mining Caverns Neutral Cavern Room Charlie 2

#include <std.h>
#include "../defs.h"
inherit INH+"nucavern";

void create(){
   ::create();
   set_exits(([
      "north":RMS"nucavernb2",
      "northeast":RMS"nucavernb3",
      "south":RMS"nucavernd2",
      "west":RMS"nucavernc1",
      "northwest":RMS"nucavernb1",
   ]));
}