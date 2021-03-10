#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"v75",
   "west" : ROOMS+"shore9",
   "north" : ROOMS+"v68",
   "south" : ROOMS+"shore7",
   "southeast" : ROOMS+"shore6",
   ]));
}
