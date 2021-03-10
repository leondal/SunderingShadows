//Titania 10/21/2019
//Shadow Sewers, Rat Tunnel, Room 2

#include <std.h>
#include "../defs.h"
inherit INH"tunnel";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"tunnel3",
      "west" : ROOMS"tunnel1",
   ]));
}
