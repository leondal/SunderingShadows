//nest2.c
#include "../kildare.h"

inherit NEST;

void create()
{
   ::create();
   set_climb_exits(([
      "descend":({ROOMS"ptrail21",10,4,100}),
      ]));
}
