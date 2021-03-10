#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "south" : ROOMS+"dt8",
   "north" : ROOMS+"dt10",
   ]) );
}
