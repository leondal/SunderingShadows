#include <std.h>
#include "road.h"

inherit ROAD;

void create()
{
   ::create();
    set_long(::query_long()+"%^ORANGE%^A small path leads into the woods to the south here. There is a sign you can read in the front of the forest.
");
   set_exits(([
   "south": "/d/darkwood/yntala/rooms/forest175",
   "west" : PATH+"road7",
   "east" : PATH+"road5",
   ]));
}
void reset(){
   ::reset();
    if(!present("sign"))
      new("/d/common/obj/areas/yntala_sign.c")->move(TO);
}
