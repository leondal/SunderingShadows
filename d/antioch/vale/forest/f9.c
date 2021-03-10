#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "northwest" : ROOMS+"v18",
   "northeast" : FPATH+"f11",
   "east" : FPATH+"f8",
   ]));
}
