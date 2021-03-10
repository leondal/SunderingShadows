#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"plains17",
   "north" : ROOMS+"plains13",
   ]));
}
