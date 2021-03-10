#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"v21",
   "north" : ROOMS+"v23",
   "northwest" : ROOMS+"v24",
   "southeast" : ROOMS+"v1",
   "west" : ROOMS+"e1710",
   ]) );
   set_invis_exits(({"west"}));
}
