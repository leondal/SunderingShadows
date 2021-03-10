#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"v61",
   "west" : FPATH+"f54",
   ]));
}
