#include <std.h>
#include "../vale.h"
inherit WALL;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c12",
   "east" : ROOMS+"c14",
   "south" : ROOMS+"c6",
   "northeast" : ROOMS+"c22",
   ]));
}
