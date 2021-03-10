#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "east" : FPATH+"f58",
   "west" : FPATH+"f60",
   ]));
}
