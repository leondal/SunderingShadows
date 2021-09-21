#include <std.h>
#include "../jarmila.h"

inherit STORAGE"tentcity.c";

void create(){
   ::create();
   set_exits(([
      "northeast" : ROOMS"2",
      "southeast" : "/d/antioch/greaterantioch/rooms/foothills/foothills17.c",
   ]));

}
