#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"meadow5",
   "east" : ROOMS+"meadow3",
   "south" : ROOMS+"meadow7",
   ]));
}
