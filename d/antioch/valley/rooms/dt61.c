#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "southeast" : ROOMS+"dt60",
   "northeast" : ROOMS+"dt62",
   ]) );
}
