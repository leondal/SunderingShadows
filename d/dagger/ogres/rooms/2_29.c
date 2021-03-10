#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"2_1",
      "southwest" : ROOMS"2_30",

   ]));

}


