#include <std.h>
#include "../vale.h"
inherit RBANK;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"rbank7",
   "west" : ROOMS+"rbank9",
   "north" : ROOMS+"v10",
   "southeast" : ROOMS+"rbank6",
   ]));
}
