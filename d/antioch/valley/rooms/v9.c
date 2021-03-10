#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "west" : ROOMS+"v8",
   "east" : ROOMS+"v10",
   "north" : ROOMS+"v13",
   "south" : ROOMS+"e1520",
   ]) );
   set_invis_exits(({"south"}));
}
