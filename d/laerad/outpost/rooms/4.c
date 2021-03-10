#include <std.h>
#include "../outpost.h"

inherit STORAGE"coastline";

void create(){
   ::create();
   set_exits(([
      "southwest" : ROOMS"3",
      "northeast" : ROOMS"5",
	  "east" : ROOMS"6"
   ]));

}