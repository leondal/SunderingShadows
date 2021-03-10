#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"2_2",
      "east" : ROOMS"2_14",
      "west" : ROOMS"2_29",
      "northeast" : ROOMS"2_7",
      "southeast" : ROOMS"2_23",
      "southwest" : ROOMS"2_27",
      "northwest" : ROOMS"2_37",
     
   ]));

}
