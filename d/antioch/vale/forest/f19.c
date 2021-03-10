#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "north" : FPATH+"f22",
   "south" : FPATH+"f18",
   "northwest" : FPATH+"f21",
   ]));
}
