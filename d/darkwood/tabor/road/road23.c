#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
   set_exits(([
   "northeast" : PATH+"road22",
   "south" : PATH+"road24",
   ]));
}
