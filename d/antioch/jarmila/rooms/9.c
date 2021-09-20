
#include <std.h>
#include "../jarmila.h"

inherit STORAGE"military.c";

void create(){
   ::create();
   set_exits(([

	  "south" : ROOMS"8",
	  "northwest" : ROOMS"10",


   ]));

}
