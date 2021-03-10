//Titania 10/21/2019
//Dirt Tunnel, Room 1

#include <std.h>
#include "../defs.h"
inherit INH"dirttunnel";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"dirttunnel2",
	  "out" : "/d/shadow/room/forest/owagon38.c",
   ]));
}
