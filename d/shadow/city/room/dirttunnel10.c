//Titania 10/21/2019
//Dirt Tunnel, Room 10

#include <std.h>
#include "../defs.h"
inherit INH"dirttunnel";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"dirttunnel9",
	  "south" : ROOMS"dirttunnel11",
   ]));
}
