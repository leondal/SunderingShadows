#include <std.h>
#include "../valley.h"
inherit VAL_1;

void create()
{
   ::create();
   set_exits( ([
   "southeast" : ROOMS+"v28",
   "north" : ROOMS+"v31",
   "east" : ROOMS+"v29",
   "west" : ROOMS+"e2106",
   "northwest" : ROOMS+"v32",
   ]) );
   set_invis_exits(({"west"}));
}
