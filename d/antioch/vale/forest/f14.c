#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "northeast" : FPATH+"f18",
   "east" : FPATH+"f15",
   ]));
}
