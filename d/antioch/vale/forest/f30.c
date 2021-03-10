#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "northwest" : FPATH+"f36",
   "south" : FPATH+"f28",
   "west" : FPATH+"f31",
   ]));
}
