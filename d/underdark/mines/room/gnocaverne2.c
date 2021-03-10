//Octothorpe (1/25/09)
//Underdark Mining Caverns Neutral Cavern Room Echo 2

#include <std.h>
#include "../defs.h"
inherit INH+"gnocavern2";

void create(){
   ::create();
   set_exits(([
      "north":RMS"gnocavernd2",
      "east":RMS"gnocaverne3",
      "southeast":RMS"gnocavernf3",
      "southwest":RMS"gnocavernf1",
	  "northwest":RMS"gnocavernd1",
   ]));
}