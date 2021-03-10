#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "north" : FPATH+"f17",
   "south" : FPATH+"f12",
   "southwest" : FPATH+"f13",
   ]));
}
