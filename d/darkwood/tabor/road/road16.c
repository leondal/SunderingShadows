#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
   set_long(::query_long()+"%^RESET%^A small path branches away from the road here, leading northwest through a break in the trees up to a vast stone building.
");
   set_exits(([
   "northeast" : PATH+"road15",
   "south" : PATH+"road17",
   "northwest" : "/d/guilds/circleoflight/rooms/path",
   ]));
}
