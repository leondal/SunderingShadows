#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "north" : ROOMS+"dt31",
   "southwest" : ROOMS+"dt29",
   ]) );
}
