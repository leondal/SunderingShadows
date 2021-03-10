#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"v15",
   "west" : ROOMS+"v17",
   "south" : ROOMS+"v6",
   "north" : ROOMS+"g6",
   ]) );
}
