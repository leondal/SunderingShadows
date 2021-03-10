#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_exits(([
   "north" : ROOMS+"shore14",
   "south" : ROOMS+"shore16",
   "northeast" : ROOMS+"shore13",
   ]));
}
