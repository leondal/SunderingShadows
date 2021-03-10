#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "north" : FPATH+"f38",
   "east" : FPATH+"f32",
   "west" : FPATH+"f34",
   ]));
}
