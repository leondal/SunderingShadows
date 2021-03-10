#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"shore12",
   "north" : ROOMS+"shore10",
   "northeast" : ROOMS+"shore9",
   "southwest" : ROOMS+"shore13",
   ]));
}
