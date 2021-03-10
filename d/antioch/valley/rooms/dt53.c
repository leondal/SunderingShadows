#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "southeast" : ROOMS+"dt52",
   "northeast" : ROOMS+"dt54",
   "northwest" : ROOMS+"dt57",
   ]) );
}
