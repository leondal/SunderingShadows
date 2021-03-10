//Titania 10/21/2019
//Dirt Tunnel, Room 14

#include <std.h>
#include "../defs.h"
inherit INH"dirttunnel";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"dirttunnel13",
	  "southeast" : ROOMS"dirttunnel15",
   ]));
}
