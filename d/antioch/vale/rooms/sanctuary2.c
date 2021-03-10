#include <std.h>
#include "../vale.h"
inherit SANCTUARY;

void create()
{
   ::create();
   set_exits(([
   "northwest" : ROOMS+"sanctuary3",
   "east" : ROOMS+"sanctuary1",
   ]));
}