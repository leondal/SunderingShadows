#include <std.h>
#include "../valley.h"
inherit VAL_1;

void create()
{
   ::create();
   set_exits( ([
   "northwest" : ROOMS+"v22",
   "east" : ROOMS+"v2",
   "north" : ROOMS+"v21",
   "south" : ROOMS+"e1512",
   "west" : ROOMS+"e1611",
   ]) );
   set_invis_exits(({"south","west"}));
}
