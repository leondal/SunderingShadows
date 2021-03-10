#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "northwest" : ROOMS+"v39",
   "southeast" : FPATH+"f19",
   ]));
}
