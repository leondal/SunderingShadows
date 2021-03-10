#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "north" : ROOMS+"dt26",
   "southeast" : ROOMS+"dt28",
   ]) );
}
