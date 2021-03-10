#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "south" : FPATH+"f58",
   "east" : FPATH+"f54",
   "west" : FPATH+"f56",
   ]));
}
