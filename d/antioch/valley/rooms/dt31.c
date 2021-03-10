#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "north" : ROOMS+"ogrecamp",
   "south" : ROOMS+"dt30",
   ]) );
}
