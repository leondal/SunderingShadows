#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "northwest" : FPATH+"f4",
   "south" : FPATH+"f3",
   "west" : FPATH+"f1",
   ]));
}
