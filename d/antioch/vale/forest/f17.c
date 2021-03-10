#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "south" : FPATH+"f16",
   "west" : FPATH+"f18",
   ]));
}
