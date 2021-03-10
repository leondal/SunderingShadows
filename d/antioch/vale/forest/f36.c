#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "west" : FPATH+"f37",
   "southeast" : FPATH+"f30",
   "southwest" : FPATH+"f32",
   ]));
}
