#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"ccenter.c";

void create(){
   ::create();
   set_exits(([
      "east":ROOMS"30",
	  "west" : ROOMS"28",
      //"north" : ROOMS"26",
	  "south" : ROOMS"24"
   ]));

}