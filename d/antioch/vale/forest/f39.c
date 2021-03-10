#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "east" : FPATH+"f38",
   "southwest" : FPATH+"f35",
   ]));
}
