#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "east" : ROAD+"road47",
   "west" : ROOMS+"plains2",
   "south" : ROOMS+"plains4",
   ]));
}
