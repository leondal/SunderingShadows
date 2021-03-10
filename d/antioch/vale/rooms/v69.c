#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v70",
   "east" : ROOMS+"v68",
   "northeast" : ROOMS+"v62",
   "south" : ROOMS+"shore9",
   ]));
}
