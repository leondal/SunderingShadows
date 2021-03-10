//ptrail8.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   set_exits(([
      "southwest" : ROOMS"ptrail7",
      "northwest" : ROOMS"ptrail9",
      "southeast" : ROOMS"ptrail17"
      ]));
}
