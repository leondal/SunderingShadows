#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void create(){
   ::create();
   set_exits(([
      "northeast" : ROOMS"2_5",
      "south" : ROOMS"2_3",
   ]));

}