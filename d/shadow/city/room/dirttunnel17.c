//Titania 10/21/2019
//Dirt Tunnel, Room 17

#include <std.h>
#include "../defs.h"
inherit INH"dirttunnel";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"dirttunnel16",
	  "south" : ROOMS"dirttunnel18",
   ]));
}
