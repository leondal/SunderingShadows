#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"dt57",
   "northwest" : ROOMS+"dt59",
   ]) );
}
