#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v48",
   "east" : ROOMS+"v46",
   "south" : ROOMS+"c38",
   ]));
}
