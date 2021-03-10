#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v38",
   "northeast" : ROOMS+"v40",
   "north" : ROOMS+"v39",
   "south" : ROOMS+"v36",
   ]));
}
