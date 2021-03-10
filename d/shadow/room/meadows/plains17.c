#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"plains16",
   "east" : ROOMS+"plains18",
   "north" : ROOMS+"plains14",
   ]));
}
