#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v67",
   "east" : ROOMS+"v65",
   "north" : ROOMS+"v64",
   "south" : ROOMS+"v76",
   ]));
}
