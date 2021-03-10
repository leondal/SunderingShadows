#include "../valley.h"
inherit DTRAIL2;

void create()
{
   ::create();
   set_exits( ([
   "southwest" : ROOMS+"dt34",
   "north" : ROOMS+"dt40",
   "southeast" : ROOMS+"dt36",
   ]) );
}
