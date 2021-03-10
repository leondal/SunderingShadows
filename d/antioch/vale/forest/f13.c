#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "northeast" : FPATH+"f16",
   ]));
}
