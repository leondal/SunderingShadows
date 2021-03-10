//Octothorpe (1/25/09)
//Underdark Mining Caverns Neutral Cavern Room Delta 2

#include <std.h>
#include "../defs.h"
inherit INH+"gnocavern2";

void create(){
   ::create();
   set_exits(([
      "north":RMS"gnocavernc2",
      "southeast":RMS"gnocaverne3",
      "south":RMS"gnocaverne2",
      "west":RMS"gnocavernd1",
   ]));
}