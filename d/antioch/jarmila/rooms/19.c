
#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "southeast" : ROOMS"18",
      "northwest" : ROOMS"22",
	  "northeast" : ROOMS"20", 

   ]));
}

