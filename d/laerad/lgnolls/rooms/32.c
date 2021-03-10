#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"common_ground.c";

void create(){
   ::create();
   set_exits(([
      "northeast":ROOMS"33",
	  "southwest" : ROOMS"31",
      //"north" : ROOMS"26",
	  //"south" : ROOMS"25"
   ]));

}