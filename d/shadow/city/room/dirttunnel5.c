//Titania 10/21/2019
//Dirt Tunnel, Room 5

#include <std.h>
#include "../defs.h"
inherit INH"dirttunnel";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"dirttunnel4",
	  "south" : ROOMS"dirttunnel6",
   ]));
}
