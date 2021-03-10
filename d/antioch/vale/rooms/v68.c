#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v69",
   "east" : ROOMS+"v67",
   "north" : ROOMS+"v62",
   "south" : ROOMS+"shore8",
   ]));
}
