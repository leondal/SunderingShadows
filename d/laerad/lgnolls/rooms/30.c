#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"ccenter.c";

void create(){
   ::create();
   set_exits(([
      "northeast":ROOMS"31",
	  "west" : ROOMS"29",
      //"north" : ROOMS"26",
	  "south" : ROOMS"25"
   ]));

}