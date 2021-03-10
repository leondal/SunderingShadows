#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "east" : FPATH+"f2",
   "west" : ROOMS+"rbank1",
   ]));
}
