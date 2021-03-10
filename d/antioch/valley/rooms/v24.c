#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"v23",
   "north" : ROOMS+"v25",
   "northwest" : ROOMS+"v26",
   "southeast" : ROOMS+"v22",
   "west" : ROOMS+"e1809",
   ]) );
   set_invis_exits(({"west"}));
}
