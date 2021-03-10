#include <std.h>
#include "../valley.h"
inherit VAL_1;

void create()
{
   ::create();
   set_exits( ([
   "north" : ROOMS+"g85",
   "east" : ROOMS+"g86",
   "west" : ROOMS+"v36",
   "south" : ROOMS+"v34",
   ]) );
}
