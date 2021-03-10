#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"v63",
   "northeast" : ROOMS+"v61",
   "southwest" : ROOMS+"v69",
   "south" : ROOMS+"v68",
   ]));
}
