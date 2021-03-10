#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "north" : ROOMS+"v73",
   "south" : ROOMS+"shore14",
   "east" : ROOMS+"shore12",
   ]));
}
