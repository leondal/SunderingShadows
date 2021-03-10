#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"plains8",
   "north" : ROOMS+"plains6",
   ]));
}
