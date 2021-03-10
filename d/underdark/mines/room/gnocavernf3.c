//Octothorpe (2/7/09)
//Underdark Mining Caverns Neutral Cavern Room Foxtrot 3

#include <std.h>
#include "../defs.h"
inherit INH+"gnocavern2";

void create(){
   ::create();
   set_exits(([
      "northwest":RMS"gnocaverne2",
      "north":RMS"gnocaverne3",
   ]));
}