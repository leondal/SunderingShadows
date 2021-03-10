#include <std.h>
#include "../vale.h"
inherit SANCTUARY;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"sanctuary5",
   "southwest" : ROOMS+"sanctuary3",
   ]));
}
