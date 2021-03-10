#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"ccenter.c";

void create(){
   ::create();
   set_exits(([
      "east":ROOMS"23",
	  "west" : ROOMS"21",
      "north" : ROOMS"27",
	  "south" : ROOMS"17"
   ]));

}