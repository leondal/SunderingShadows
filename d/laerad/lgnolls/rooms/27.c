#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"ccenter.c";

void create(){
   ::create();
   set_exits(([
      "east":ROOMS"28",
	  "west" : ROOMS"26",
      //"north" : ROOMS"26",
	  "south" : ROOMS"22"
   ]));

}