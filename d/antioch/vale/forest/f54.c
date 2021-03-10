#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "south" : FPATH+"f57",
   "east" : FPATH+"f53",
   "west" : FPATH+"f55",
   ]));
}
