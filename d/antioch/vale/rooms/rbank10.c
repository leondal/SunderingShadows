#include <std.h>
#include "../vale.h"
inherit RBANK;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"rbank9",
   "west" : ROOMS+"rbank11",
   "north" : ROOMS+"v8",
   "south" : ROOMS+"rbank17",
   "northwest" : ROOMS+"rbank12",
   ]));
}
