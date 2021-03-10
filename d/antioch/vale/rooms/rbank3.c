#include <std.h>
#include "../vale.h"
inherit RBANK;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"rbank2",
   "north" : ROOMS+"rbank4",
   "northwest" : ROOMS+"rbank5",
   ]));
}
