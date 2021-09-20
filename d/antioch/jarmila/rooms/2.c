
#include <std.h>
#include "../jarmila.h"

inherit STORAGE"tentcity.c";

void create(){
   ::create();
   set_exits(([
   "northeast" : ROOMS"4",
	  "southwest" : ROOMS"1",
	  "northwest" : ROOMS"3",

   ]));

}
