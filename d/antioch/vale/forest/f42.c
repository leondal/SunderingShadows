#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "south" : ROOMS+"v51",
   "east" : FPATH+"f41",
   "west" : FPATH+"f43",
   ]));
}
