#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"v11",
   "west" : ROOMS+"v13",
   "south" : ROOMS+"v10",
   "north" : ROOMS+"g10",
   ]) );
}
