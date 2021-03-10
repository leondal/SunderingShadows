#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void create(){
   ::create();
   set_exits(([
      "northeast" : ROOMS"2_30",
      "west" : ROOMS"2_32",

   ]));

}


