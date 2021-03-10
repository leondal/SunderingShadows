#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"plains7",
   "east" : ROOMS+"plains9",
   "north" : ROOMS+"plains5",
   ]));
}
