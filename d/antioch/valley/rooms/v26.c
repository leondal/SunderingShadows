#include <std.h>
#include "../valley.h"
inherit VAL_1;

void create()
{
   ::create();
   set_exits( ([
   "north" : ROOMS+"v27",
   "east" : ROOMS+"v25",
   "west" : ROOMS+"e1908",
   "northwest" : ROOMS+"v28",
   "southeast" : ROOMS+"v24",
   ]) );
   set_invis_exits(({"west"}));
}
