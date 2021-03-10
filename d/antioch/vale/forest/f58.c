#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "north" : FPATH+"f55",
   "south" : ROOMS+"v70",
   "east" : FPATH+"f57",
   "west" : FPATH+"f59",
   ]));
}
