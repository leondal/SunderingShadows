#include <std.h>
#include "../jarmila.h"

inherit STORAGE"tentcity.c";

void create(){
   ::create();
   set_exits(([

	  "southeast" : ROOMS"6",
	  "northeast" : ROOMS"8",


   ]));

}
