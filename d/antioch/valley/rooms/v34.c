#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "north" : ROOMS+"v35",
   "northwest" : ROOMS+"v36",
   "east" : ROOMS+"v33",
   "west" : ROOMS+"e2304",
   "southeast" : ROOMS+"v32",
   ]) );
   set_invis_exits(({"west"}));
}
