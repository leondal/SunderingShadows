#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"ccenter.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"17",
      "north" : ROOMS"23",
	  "east" : ROOMS"19"
   ]));

}