#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v64",
   "east" : ROOMS+"c49",
   "south" : ROOMS+"v65",
   "north" : ROOMS+"v59",
   ]));
}
