#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"common_ground.c";

void create(){
   ::create();
   set_exits(([
      "northeast":ROOMS"32",
	  "southwest" : ROOMS"30",
      //"north" : ROOMS"26",
	  //"south" : ROOMS"25"
   ]));

}