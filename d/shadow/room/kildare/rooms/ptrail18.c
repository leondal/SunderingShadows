//ptrail18.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   set_exits(([
      "southwest" : ROOMS"ptrail17",
      "east" : ROOMS"ptrail19"
      ]));
}
