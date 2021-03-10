#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"plains15",
   "east" : ROOMS+"plains13",
   "south" : ROOMS+"plains17",
   "north" : ROOMS+"plains11",
   ]));
}
