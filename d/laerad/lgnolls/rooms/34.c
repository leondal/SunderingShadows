#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"common_ground.c";

void create(){
   ::create();
   set_exits(([
      "east":ROOMS"35",
	  "west" : ROOMS"33",
      //"north" : ROOMS"26",
	  //"south" : ROOMS"25"
   ]));

}