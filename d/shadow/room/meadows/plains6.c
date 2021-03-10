#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"plains5",
   "south" : ROOMS+"plains7",
   "north" : ROOMS+"plains1",
   ]));
}
