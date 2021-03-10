#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v47",
   "east" : ROOMS+"v45",
   "south" : ROOMS+"c37",
   ]));
}
