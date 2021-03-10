#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"v17",
   "west" : ROOMS+"v19",
   "south" : ROOMS+"v4",
   "north" : ROOMS+"g4",
   ]) );
}
