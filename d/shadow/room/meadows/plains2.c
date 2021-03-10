#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"plains3",
   "west" : ROOMS+"plains1",
   "south" : ROOMS+"plains5",
   ]));
}
