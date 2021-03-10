#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "southwest" : FPATH+"f27",
   ]));
}
