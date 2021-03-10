#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v46",
   "east" : ROOMS+"v44",
   "south" : ROOMS+"c36",
   ]));
}
