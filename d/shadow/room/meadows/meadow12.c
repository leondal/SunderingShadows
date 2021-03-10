#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"meadow11",
   "east" : ROAD+"road34",
   "north" : ROOMS+"meadow9",
   "south" : ROOMS+"meadow13",
   ]));
}
