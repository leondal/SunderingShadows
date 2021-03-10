#include <std.h>
#include "../outpost.h"

inherit STORAGE"road";

void create(){
   ::create();
   set_exits(([
      //"southwest" : ROOMS"4",
      //"northeast" : ROOMS"5",
	  "east" : ROOMS"7",
	  "west" : ROOMS"4",
   ]));

}