#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_exits(([
   "west" : ROAD+"road36",
   "east" : ROOMS+"meadow18",
   "south" : ROAD+"road37",
   ]));
}
