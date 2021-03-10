#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "southeast" : ROOMS+"dt10",
   "northwest" : ROOMS+"dt12",
   ]) );
}
