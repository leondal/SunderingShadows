#include <std.h>
#include "../vale.h"
inherit RBANK;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"rbank10",
   "north" : ROOMS+"rbank12",
   "northwest" : ROOMS+"rbank13",
   "southeast" : ROOMS+"rbank17",
   ]));
}
