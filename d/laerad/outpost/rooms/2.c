#include <std.h>
#include "../outpost.h"

inherit STORAGE"coastline";

void create(){
   ::create();
   set_exits(([
      "southwest" : ROOMS"1",
      "northeast" : ROOMS"3",
	  "east" : ROOMS"11"
   ]));

}