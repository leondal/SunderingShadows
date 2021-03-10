#include <std.h>
#include "../vale.h"
inherit SANCTUARY;

void create()
{
   ::create();
   set_exits(([
   "northwest" : ROOMS+"sanctuary7",
   "southwest" : ROOMS+"sanctuary9",
   ]));
}
