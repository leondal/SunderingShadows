#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "west" : ROOMS+"v1",
   "east" : ROOMS+"v3",
   "north" : ROOMS+"v20",
   "south" : ROOMS+"e1513",
   ]) );
   set_invis_exits(({"south"}));
}
