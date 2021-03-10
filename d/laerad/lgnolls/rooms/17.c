#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"ccenter.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"16",
      "north" : ROOMS"22",
	  "east" : ROOMS"18"
   ]));

}