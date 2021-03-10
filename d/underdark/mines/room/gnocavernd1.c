//Octothorpe (1/25/09)
//Underdark Mining Caverns Neutral Cavern Room Delta 1

#include <std.h>
#include "../defs.h"
inherit INH+"gnocavern2";

void create(){
   ::create();
   set_exits(([
      "northeast":RMS"gnocavernc2",
      "southeast":RMS"gnocaverne2",
      "east":RMS"gnocavernd2",
   ]));
}