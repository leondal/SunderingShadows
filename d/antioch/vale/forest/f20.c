#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "southeast" : FPATH+"f18",
   ]));
}
