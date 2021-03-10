#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"plains14",
   "south" : ROOMS+"plains18",
   "north" : ROOMS+"plains12",
   ]));
}
