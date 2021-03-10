#include "../valley.h"
inherit DTRAIL2;

void create()
{
   ::create();
   set_exits( ([
   "west" : ROOMS+"dt29",
   "east" : ROOMS+"dt33",
   ]) );
}
