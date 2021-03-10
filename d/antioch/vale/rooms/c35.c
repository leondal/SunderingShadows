#include <std.h>
#include "../vale.h"
inherit WALL;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"c34",
   "north" : ROOMS+"c39",
   "southeast" : ROOMS+"c29",
   "northwest" : ROOMS+"c40",
   ]));
}
