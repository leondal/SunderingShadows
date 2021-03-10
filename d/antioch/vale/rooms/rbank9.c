#include <std.h>
#include "../vale.h"
inherit RBANK;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"rbank8",
   "west" : ROOMS+"rbank10",
   "north" : ROOMS+"v9",
   "southwest" : ROOMS+"rbank17",
   ]));
}
