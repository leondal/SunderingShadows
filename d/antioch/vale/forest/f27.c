#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "north" : FPATH+"f28",
   "northeast" : FPATH+"f29",
   ]));
}
