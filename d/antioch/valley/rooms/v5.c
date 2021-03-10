#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "west" : ROOMS+"v4",
   "east" : ROOMS+"v6",
   "north" : ROOMS+"v17",
   "south" : ROOMS+"e1516",
   ]) );
   set_invis_exits(({"south"}));
}
