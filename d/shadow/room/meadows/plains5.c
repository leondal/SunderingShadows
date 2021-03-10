#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"plains6",
   "east" : ROOMS+"plains4",
   "south" : ROOMS+"plains8",
   "north" : ROOMS+"plains2",
   ]));
}
