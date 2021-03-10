#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "north" : ROOMS+"dt14",
   "southeast" : ROOMS+"dt12",
   "southwest" : ROOMS+"dt16",
   ]) );
}
