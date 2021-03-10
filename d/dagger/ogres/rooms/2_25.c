#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"2_28",
      "northeast" : ROOMS"2_24",
      "northwest" : ROOMS"2_26",
   ]));

}


