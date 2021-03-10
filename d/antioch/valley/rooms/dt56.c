#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "south" : ROOMS+"dt55",
   ]) );
}
