#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "east" : FPATH+"f45",
   "west" : FPATH+"f47",
   ]));
}
