#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c27",
   "east" : ROOMS+"v37",
   "north" : ROOMS+"c32",
   "south" : ROOMS+"c26",
   ]));
}
