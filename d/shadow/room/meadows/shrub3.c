#include <std.h>
#include "meadow.h"
inherit SHRUB;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"shrub2",
   "south" : ROOMS+"shrub4",
   ]));
}
