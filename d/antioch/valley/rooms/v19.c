#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"v18",
   "west" : ROOMS+"v20",
   "south" : ROOMS+"v3",
   "north" : ROOMS+"g3",
   ]) );
}
