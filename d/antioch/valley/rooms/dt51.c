#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "southwest" : ROOMS+"dt50",
   "north" : ROOMS+"dt52",
   ]) );
}
