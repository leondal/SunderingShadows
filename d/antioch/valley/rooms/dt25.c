#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "south" : ROOMS+"dt24",
   "north" : ROOMS+"orccave",
   ]) );
}
