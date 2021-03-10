#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "southwest" : ROOMS+"dt54",
   "north" : ROOMS+"dt56",
   ]) );
}
