#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void create(){
   ::create();
   set_exits(([
      "northeast" : ROOMS"2_29",
      "southwest" : ROOMS"2_31",

   ]));

}


