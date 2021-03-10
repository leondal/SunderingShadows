//Titania 10/21/2019
//Dirt Tunnel, Room 13

#include <std.h>
#include "../defs.h"
inherit INH"dirttunnel";

void create(){
   ::create();
   set_exits(([
      "northeast" : ROOMS"dirttunnel12",
	  "south" : ROOMS"dirttunnel14",
   ]));
}
