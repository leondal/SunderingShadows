#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"plains2",
   "south" : ROOMS+"plains6",
   ]));
}
