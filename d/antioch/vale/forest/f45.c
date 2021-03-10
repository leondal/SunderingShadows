#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "southeast" : ROOMS+"v55",
   "east" : FPATH+"f44",
   "west" : FPATH+"f46",
   ]));
}
