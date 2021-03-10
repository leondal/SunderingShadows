#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v49",
   "east" : ROOMS+"v47",
   "northwest" : ROOMS+"v50",
   "south" : ROOMS+"c39",
   ]));
}
