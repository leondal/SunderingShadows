#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROAD+"road47",
   "east" : ROOMS+"plains11",
   "south" : ROOMS+"plains15",
   ]));
}
