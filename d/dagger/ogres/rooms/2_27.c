#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"2_26",
      "northeast" : ROOMS"2_1",
   ]));

}


