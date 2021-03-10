#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"meadow6",
   "east" : ROOMS+"meadow8",
   "north" : ROOMS+"meadow4",
   "south" : ROOMS+"meadow10",
   ]));
}
