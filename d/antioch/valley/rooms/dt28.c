#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "southeast" : ROOMS+"dt29",
   "northwest" : ROOMS+"dt27",
   ]) );
}
