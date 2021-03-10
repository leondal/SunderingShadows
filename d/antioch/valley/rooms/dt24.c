#include "../valley.h"
inherit DTRAIL2;

void create()
{
   ::create();
   set_exits( ([
   "east" : ROOMS+"dt23",
   "north" : ROOMS+"dt25",
   ]) );
}
