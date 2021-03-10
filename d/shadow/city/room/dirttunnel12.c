//Titania 10/21/2019
//Dirt Tunnel, Room 12

#include <std.h>
#include "../defs.h"
inherit INH"dirttunnel";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"dirttunnel11",
	  "southwest" : ROOMS"dirttunnel13",
   ]));
}
