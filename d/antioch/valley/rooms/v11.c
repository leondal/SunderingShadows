#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "west" : ROOMS+"v12",
   "southwest" : ROOMS+"v10",
   "east" : ROOMS+"e1723",
   "south" : ROOMS+"e1622",
   "northeast" : ROOMS+"v90",
   "north" : ROOMS+"g11",
   ]) );
   set_invis_exits(({"south","east"}));
}
