#include <std.h>\
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "west" : ROOMS+"v5",
   "east" : ROOMS+"v7",
   "north" : ROOMS+"v16",
   "south" : ROOMS+"e1517",
   ]) );
   set_invis_exits(({"south"}));
}
