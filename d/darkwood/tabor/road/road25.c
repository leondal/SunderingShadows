#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
   set_exits(([
   "northwest" : PATH+"road24",
   "south" : PATH+"road26",
   ]));
}
