#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"plains12",
   "west" : ROOMS+"plains10",
   "south" : ROOMS+"plains14",
   ]));
}
