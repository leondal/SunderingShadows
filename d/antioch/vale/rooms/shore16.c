#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_exits(([
   "north" : ROOMS+"shore15",
   "south" : ROOMS+"shore17",
   ]));
}
