#include <std.h>
#include "../vale.h"
inherit RBANK;

void create()
{
   ::create();
   set_exits(([
   "southeast" : ROOMS+"rbank2",
   "north" : ROOMS+"v6",
   "east" : ROOMS+"v1",
   "west" : ROOMS+"rbank5",
   "south" : ROOMS+"rbank3",
   ]));
}
