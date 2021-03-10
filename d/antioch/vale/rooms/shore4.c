#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"v80",
   "west" : ROOMS+"shore5",
   "south" : ROOMS+"shore3",
   "north" : ROOMS+"v79",
   "northwest" : ROOMS+"shore6",
   "southeast" : ROOMS+"shore2",
   ]));
}
