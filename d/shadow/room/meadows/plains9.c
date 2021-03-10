#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "east" : ROAD+"road49",
   "west" : ROOMS+"plains8",
   "north" : ROOMS+"plains4",
   "south" : "/d/darkwood/camps/rooms/path/path01",
   ]));
}
