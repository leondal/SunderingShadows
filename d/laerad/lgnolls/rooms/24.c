#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"ccenter.c";

void create(){
   ::create();
   set_exits(([
      "east":ROOMS"25",
	  "west" : ROOMS"23",
      "north" : ROOMS"29",
	  "south" : ROOMS"19"
   ]));

}