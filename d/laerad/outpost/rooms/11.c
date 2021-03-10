#include <std.h>
#include "../outpost.h"

inherit STORAGE"road";

void create(){
   ::create();
   set_exits(([
      //"southwest" : ROOMS"4",
      //"northeast" : ROOMS"5",
	  "north" : ROOMS"clinic",
	  "west" : ROOMS"2",
	  "east" : ROOMS"10",
   ]));

}