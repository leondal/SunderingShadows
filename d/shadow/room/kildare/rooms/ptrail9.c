//ptrail9.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   set_exits(([
      "northwest" : ROOMS"ptrail10",
      "northeast" : ROOMS"ptrail12",
      "southeast" : ROOMS"ptrail8"
      ]));
}
