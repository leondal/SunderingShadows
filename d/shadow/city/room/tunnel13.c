//Titania 10/21/2019
//Shadow Sewers, Rat Tunnel, Room 13

#include <std.h>
#include "../defs.h"
inherit INH"tunnel";

void create(){
   ::create();
   set_exits(([
      "southeast" : ROOMS"chamber",
      "west" : ROOMS"tunnel12",
   ]));
}
