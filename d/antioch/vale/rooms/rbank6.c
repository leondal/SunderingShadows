#include <std.h>
#include "../vale.h"
inherit RBANK;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"rbank5",
   "north" : ROOMS+"rbank7",
   "northwest" : ROOMS+"rbank8",
   ]));
}
