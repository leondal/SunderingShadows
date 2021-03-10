#include <std.h>
#include "../vale.h"
inherit RBANK;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"rbank4",
   "west" : ROOMS+"rbank6",
   "north" : ROOMS+"v7",
   "northwest" : ROOMS+"rbank7",
   "southeast" : ROOMS+"rbank3",
   ]));
}
