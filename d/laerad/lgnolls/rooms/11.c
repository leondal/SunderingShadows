#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"ccenter.c";

void create(){
   ::create();
   
   set_exits(([
      "west" : ROOMS"19",
      "north" : ROOMS"25",
	  "south" : ROOMS"10"
   ]));

}