#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROAD+"road49",
   "east" : ROOMS+"plains17",
   "north" : ROOMS+"plains15",
   ]));
}
