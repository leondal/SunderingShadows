#include "../valley.h"
inherit DTRAIL;

void create()
{
   ::create();
   set_exits( ([
   "northwest" : ROOMS+"dt43",
   "east" : ROOMS+"dt46",
   "south" : ROOMS+"dt45",
   ]) );
}
