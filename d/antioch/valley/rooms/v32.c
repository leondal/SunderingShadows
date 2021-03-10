#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "north" : ROOMS+"v33",
   "east" : ROOMS+"v31",
   "southeast" : ROOMS+"v30",
   "northwest" : ROOMS+"v34",
   "west" : ROOMS+"e2205",
   ]) );
   set_invis_exits(({"west"}));
}
