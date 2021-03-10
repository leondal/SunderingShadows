#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"rbank16",
   "north" : ROOMS+"shore2",
   "northwest" : ROOMS+"shore3",
   ]));
}
