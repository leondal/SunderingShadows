#include <std.h>
#include "../vale.h"
inherit SANCTUARY;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"sanctuary7",
   "west" : ROOMS+"sanctuary4",
   "south" : ROOMS+"sanctuary6",
   ]));
}
