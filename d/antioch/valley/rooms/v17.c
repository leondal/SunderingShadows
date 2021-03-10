#include <std.h>
#include "../valley.h"
inherit VAL_1;

void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"v16",
   "west" : ROOMS+"v18",
   "south" : ROOMS+"v5",
   "north" : ROOMS+"g5",
   ]) );
}
