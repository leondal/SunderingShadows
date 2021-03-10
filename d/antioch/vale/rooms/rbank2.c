#include <std.h>
#include "../vale.h"
inherit RBANK;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"rbank3",
   "east" : ROOMS+"rbank1",
   "north" : ROOMS+"v1",
   "northwest" : ROOMS+"rbank4",
   ]));
}
