#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v68",
   "east" : ROOMS+"v66",
   "north" : ROOMS+"v63",
   "south" : ROOMS+"v75",
   ]));
}
