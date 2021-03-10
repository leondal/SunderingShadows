#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"shore14",
   "north" : ROOMS+"shore12",
   "northeast" : ROOMS+"shore11",
   "southwest" : ROOMS+"shore15",
   ]));
}
