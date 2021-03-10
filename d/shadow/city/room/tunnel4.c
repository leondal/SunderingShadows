//Titania 10/21/2019
//Shadow Sewers, Rat Tunnel, Room 4

#include <std.h>
#include "../defs.h"
inherit INH"tunnel";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"tunnel5",
      "west" : ROOMS"tunnel3",
   ]));
}
