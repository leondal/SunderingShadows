#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "north" : FPATH+"f16",
   "south" : FPATH+"f10",
   "southeast" : FPATH+"f11",
   ]));
}
