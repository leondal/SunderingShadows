#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "north" : FPATH+"f40",
   "northeast" : FPATH+"f39",
   ]));
}
