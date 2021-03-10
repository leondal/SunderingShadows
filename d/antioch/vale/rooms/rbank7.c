#include <std.h>
#include "../vale.h"
inherit RBANK;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"v7",
   "west" : ROOMS+"rbank8",
   "north" : ROOMS+"v11",
   "southeast" : ROOMS+"rbank5",
   "south" : ROOMS+"rbank6",
   ]));
}
