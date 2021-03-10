#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v1",
   "northeast" : ROOMS+"v3",
   "north" : ROOMS+"v4",
   "south" : ROOMS+"rbank1",
   ]));
}
