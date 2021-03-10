#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"common_ground.c";

void create(){
   ::create();
   set_exits(([
      "east":ROOMS"26",
	  "west" : ROOMS"37",
      //"north" : ROOMS"26",
	  //"south" : ROOMS"25"
   ]));

}