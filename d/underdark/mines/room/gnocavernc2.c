//Octothorpe (1/25/09)
//Underdark Mining Caverns Neutral Cavern Room Charlie 2

#include <std.h>
#include "../defs.h"
inherit INH+"gnocavern2";

void create(){
   ::create();
   set_exits(([
      "northeast":RMS"gnocavernb3",
      "southwest":RMS"gnocavernd1",
      "south":RMS"gnocavernd2",
   ]));
}