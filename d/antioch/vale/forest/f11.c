#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "northwest" : FPATH+"f12",
   "southwest" : FPATH+"f9",
   ]));
}
