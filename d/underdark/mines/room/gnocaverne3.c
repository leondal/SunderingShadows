//Octothorpe (1/25/09)
//Underdark Mining Caverns Neutral Cavern Room Echo 3

#include <std.h>
#include "../defs.h"
inherit INH+"gnocavern2";

void create(){
   ::create();
   set_exits(([
      "northwest":RMS"gnocavernd2",
      "west":RMS"gnocaverne2",
      "south":RMS"gnocavernf3",
   ]));
}