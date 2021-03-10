#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
   set_exits(([
   "west" : PATH+"road9",
   "east" : PATH+"road7",
   ]));
}
