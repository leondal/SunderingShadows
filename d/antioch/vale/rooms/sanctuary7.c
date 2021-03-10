#include <std.h>
#include "../vale.h"
inherit SANCTUARY;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"sanctuary5",
   "southeast" : ROOMS+"sanctuary8",
   ]));
}