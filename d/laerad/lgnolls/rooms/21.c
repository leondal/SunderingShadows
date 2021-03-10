#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"ccenter.c";

void create(){
   ::create();
   set_exits(([
      "east":ROOMS"22",
	  //"west" : ROOMS"21",
      "north" : ROOMS"26",
	  "south" : ROOMS"16"
   ]));

}