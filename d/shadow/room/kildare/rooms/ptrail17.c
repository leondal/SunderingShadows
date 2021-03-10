//ptrail17.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   set_exits(([
      "northwest" : ROOMS"ptrail8",
      "northeast" : ROOMS"ptrail18"
      ]));
}
