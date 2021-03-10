#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "west" : ROOMS+"v2",
   "east" : ROOMS+"v4",
   "north" : ROOMS+"v19",
   "south" : ROOMS+"e1514",
   ]) );
   set_invis_exits(({"south"}));
}
