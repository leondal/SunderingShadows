#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "northwest" : ROOMS+"dt37",
   ]) );
}
