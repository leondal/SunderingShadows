#include "../valley.h"
inherit DTRAIL2;

void create()
{
   ::create();
   set_exits( ([
   "northwest" : ROOMS+"dt36",
   "southwest" : ROOMS+"dt38",
   "southeast" : ROOMS+"dt39",
   ]) );
}
