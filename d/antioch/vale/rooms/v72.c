#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v73",
   "east" : ROOMS+"shore10",
   "north" : ROOMS+"v71",
   "south" : ROOMS+"shore12",
   ]));
}
