
#include <std.h>
#include "../jarmila.h"

inherit STORAGE"tentcity.c";

void create(){
   ::create();
   set_exits(([

	  "southwest" : ROOMS"5",
	  "northwest" : ROOMS"7",


   ]));

}

