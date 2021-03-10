//Titania 10/21/2019
//Dirt Tunnel, Room 3

#include <std.h>
#include "../defs.h"
inherit INH"dirttunnel";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"dirttunnel2",
	  "southeast" : ROOMS"dirttunnel4",
   ]));
}
