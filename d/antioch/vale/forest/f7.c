#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "northeast" : FPATH+"f8",
   "west" : FPATH+"f6",
   ]));
}
