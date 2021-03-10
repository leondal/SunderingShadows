//ptrail4.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   set_exits(([
      "southeast" : ROOMS"ptrail3",
      "northwest" : ROOMS"ptrail5",
      "northeast" : ROOMS"ptrail6"
      ]));
}
