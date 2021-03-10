#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"ccenter.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"18",
      "north" : ROOMS"24",
	  "east" : ROOMS"11"
   ]));

}