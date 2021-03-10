#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
   set_exits(([
   "north" : PATH+"road27",
   "south" : "/d/tharis/road/wroad30",
   ]));
}
