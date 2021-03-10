#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"ccenter.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"24",
      "north" : ROOMS"30",
	  "south" : ROOMS"11"
   ]));

}