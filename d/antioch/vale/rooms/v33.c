#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c18",
   "northeast" : ROOMS+"v35",
   "southeast" : ROOMS+"v32",
   "north" : ROOMS+"v34",
   "south" : ROOMS+"v31",
   ]));
}
