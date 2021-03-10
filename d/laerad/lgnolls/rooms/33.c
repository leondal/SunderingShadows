#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"common_ground.c";

void create(){
   ::create();
   set_exits(([
      "east":ROOMS"34",
	  "southwest" : ROOMS"32",
      //"north" : ROOMS"26",
	  //"south" : ROOMS"25"
   ]));

}