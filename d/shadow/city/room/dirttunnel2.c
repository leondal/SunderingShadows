//Titania 10/21/2019
//Dirt Tunnel, Room 2

#include <std.h>
#include "../defs.h"
inherit INH"dirttunnel";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"dirttunnel1",
	  "southeast" : ROOMS"dirttunnel3",
   ]));
}
