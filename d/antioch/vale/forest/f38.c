#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "south" : FPATH+"f33",
   "west" : FPATH+"f39",
   ]));
}
