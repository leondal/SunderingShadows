//Titania 10/21/2019
//Dirt Tunnel, Room 4

#include <std.h>
#include "../defs.h"
inherit INH"dirttunnel";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"dirttunnel3",
	  "south" : ROOMS"dirttunnel5",
   ]));
}
