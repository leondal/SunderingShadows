#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c33",
   "east" : ROOMS+"v41",
   "north" : ROOMS+"v43",
   "south" : ROOMS+"c32",
   ]));
}
