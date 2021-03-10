//ptrail20.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   set_exits(([
      "northwest" : ROOMS"ptrail19",
      "east" : ROOMS"ptrail21",
      "southwest" : ROOMS"ptrail22"
      ]));
}
