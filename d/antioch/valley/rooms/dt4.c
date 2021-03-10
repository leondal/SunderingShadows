#include "../valley.h"
inherit DTRAIL;

void create()
{
  ::create();
   set_exits( ([
   "south" : ROOMS+"dt3",
   "northeast" : ROOMS+"dt5",
   ]) );
}
