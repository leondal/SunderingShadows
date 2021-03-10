#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"shore11",
   "west" : ROOMS+"v74",
   "north" : ROOMS+"v72",
   "northeast" : ROOMS+"shore10",
   "southwest" : ROOMS+"shore14",
   "south" : ROOMS+"shore13",
   ]));
}
