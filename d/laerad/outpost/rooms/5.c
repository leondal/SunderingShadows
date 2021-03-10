#include <std.h>
#include "../outpost.h"

inherit STORAGE"coastline";

void create(){
   ::create();
   set_exits(([
      "southwest" : ROOMS"4",
      //"northeast" : ROOMS"5",
	  //"east" : ROOM"6"
   ]));

}