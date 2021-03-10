#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"2_10",
      "east" : ROOMS"2_11",
      "southwest" : ROOMS"2_8",
   ]));

}
