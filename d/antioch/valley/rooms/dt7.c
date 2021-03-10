#include "../valley.h"
inherit DTRAIL2;

void create()
{
   ::create();
   set_exits( ([
   "west" : ROOMS+"dt6",
   "east" : ROOMS+"dt8",
   ]) );
}
