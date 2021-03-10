#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v30",
   "east" : ROOMS+"v32",
   "north" : ROOMS+"v33",
   "south" : ROOMS+"v20",
   ]));
}
