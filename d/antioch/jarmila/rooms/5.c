
#include <std.h>
#include "../jarmila.h"

inherit STORAGE"tentcity.c";

void create(){
   ::create();
   set_exits(([

	  "southwest" : ROOMS"4",
	  "northeast" : ROOMS"6",


   ]));

}
