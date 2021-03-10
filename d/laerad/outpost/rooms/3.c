#include <std.h>
#include "../outpost.h"

inherit STORAGE"coastline";

void create(){
   ::create();
   set_exits(([
      "southwest" : ROOMS"2",
      "northeast" : ROOMS"4",
	  //"east" : ROOM"11"
   ]));

}