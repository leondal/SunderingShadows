#include <std.h>
#include "../valley.h"
inherit VAL_1;

void create()
{
   ::create();
   set_exits( ([
   "west" : ROOMS+"v6",
   "east" : ROOMS+"v8",
   "north" : ROOMS+"v15",
   "south" : ROOMS+"e1518",
   ]) );
   set_invis_exits(({"south"}));
}
