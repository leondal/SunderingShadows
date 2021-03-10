#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"ccenter.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"15",
      "north" : ROOMS"21",
	  "east" : ROOMS"17"
   ]));

}