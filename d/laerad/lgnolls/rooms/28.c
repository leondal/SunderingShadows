#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"ccenter.c";

void create(){
   ::create();
   set_exits(([
      "east":ROOMS"29",
	  "west" : ROOMS"27",
      //"north" : ROOMS"26",
	  "south" : ROOMS"23"
   ]));

}