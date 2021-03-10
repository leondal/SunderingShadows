#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "north" : ROOMS+"v29",
   "east" : ROOMS+"v27",
   "northwest" : ROOMS+"v30",
   "west" : ROOMS+"e2007",
   "southeast" : ROOMS+"v26",
   ]) );
   set_invis_exits(({"west"}));
}
