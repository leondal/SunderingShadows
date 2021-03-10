#include <std.h>
#include "../valley.h"
inherit VAL_1;

void create()
{
   ::create();
   set_exits( ([
   "west" : ROOMS+"v9",
   "north" : ROOMS+"v12",
   "northeast" : ROOMS+"v11",
   "south" : ROOMS+"e1521",
   "east" : ROOMS+"e1622",
   ]) );
   set_invis_exits(({"east","south"}));
}
