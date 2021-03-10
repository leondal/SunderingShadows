//Titania 10/21/2019
//Dirt Tunnel, Room 9

#include <std.h>
#include "../defs.h"
inherit INH"dirttunnel";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"dirttunnel8",
	  "southeast" : ROOMS"dirttunnel10",
   ]));
}
