#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "west" : ROOMS+"dt32",
   "northeast" : ROOMS+"dt34",
   ]) );
}
