//Octothorpe (1/25/09)
//Underdark Mining Caverns Neutral Cavern Room Bravo 3

#include <std.h>
#include "../defs.h"
inherit INH+"gnocavern";

void create(){
   ::create();
   set_exits(([
      "northeast":RMS"gnocaverna4",
      "southwest":RMS"gnocavernc2",
   ]));
}