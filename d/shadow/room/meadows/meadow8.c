#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"meadow7",
   "east" : ROOMS+"meadow1",
   "north" : ROOMS+"meadow3",
   "south" : ROOMS+"meadow9",
   ]));
}
