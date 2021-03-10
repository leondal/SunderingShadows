#include <std.h>
#include "../vale.h"
inherit SANCTUARY;

void create()
{
   ::create();
   set_exits(([
   "northeast" : ROOMS+"sanctuary4",
   "southeast" : ROOMS+"sanctuary2",
   ]));
}