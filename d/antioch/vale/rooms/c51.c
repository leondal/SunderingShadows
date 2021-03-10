#include <std.h>
#include "../vale.h"
inherit WALL;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v65",
   "north" : ROOMS+"c49",
   "south" : ROOMS+"c52",
   "southeast" : ROOMS+"c53",
   "northeast" : ROOMS+"c48",
   ]));
}
