#include <std.h>
#include "../vale.h"
inherit RBANK;

void create()
{
   ::create();
   set_exits(([
   "northeast" : ROOMS+"rbank9",
   "northwest" : ROOMS+"rbank11",
   "north" : ROOMS+"rbank10",
   ]));
}
