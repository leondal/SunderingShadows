#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "north" : FPATH+"f19",
   "southwest" : FPATH+"f14",
   "east" : FPATH+"f17",
   "northwest" : FPATH+"f20",
   ]));
}
