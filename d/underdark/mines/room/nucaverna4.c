//Octothorpe (1/24/09)
//Underdark Mining Caverns Neutral Cavern Room Alpha 4

#include <std.h>
#include "../defs.h"
inherit INH+"nucavern";

void create(){
   ::create();
   set_exits(([
      "east":RMS"nucaverna5",
      "southwest":RMS"nucavernb3",
   ]));
}