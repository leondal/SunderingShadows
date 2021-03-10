#include "../valley.h"
inherit DTRAIL2;

void create()
{
   ::create();
   set_exits( ([
   "southeast" : ROOMS+"dt11",
   "northwest" : ROOMS+"dt13",
   ]) );
}
