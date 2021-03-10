//Titania 10/21/2019
//Shadow Sewers, Rat Tunnel, Room 7

#include <std.h>
#include "../defs.h"
inherit INH"tunnel";

void create(){
   ::create();
   set_exits(([
      "northeast" : ROOMS"tunnel8",
      "west" : ROOMS"tunnel6",
   ]));
}
