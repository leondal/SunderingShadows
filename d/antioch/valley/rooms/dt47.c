#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "northwest" : ROOMS+"dt46",
   "southeast" : ROOMS+"dt48",
   ]) );
}
