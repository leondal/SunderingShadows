#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "northwest" : ROOMS+"dt28",
   "northeast" : ROOMS+"dt30",
   "east" : ROOMS+"dt32",
   ]) );
}
