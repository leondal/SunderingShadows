#include "../valley.h"
inherit DTRAIL2;

void create()
{
   ::create();
   set_exits( ([
   "south" : ROOMS+"dt13",
   "north" : ROOMS+"dt15",
   ]) );
}
