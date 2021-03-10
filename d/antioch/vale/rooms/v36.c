#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c26",
   "north" : ROOMS+"v37",
   "southeast" : ROOMS+"v35",
   "south" : ROOMS+"v34",
   ]));
}
