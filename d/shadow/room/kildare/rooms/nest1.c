//nest1.c
#include "../kildare.h"

inherit NEST;

void create()
{
   ::create();
   set_climb_exits(([
      "descend":({ROOMS"ptrail11",10,4,100}),
      ]));
}
