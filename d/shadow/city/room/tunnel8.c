//Titania 10/21/2019
//Shadow Sewers, Rat Tunnel, Room 8

#include <std.h>
#include "../defs.h"
inherit INH"tunnel";

void create(){
   ::create();
   set_exits(([
      "northeast" : ROOMS"tunnel9",
      "southwest" : ROOMS"tunnel7",
   ]));
}
