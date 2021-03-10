//ptrail2.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   set_exits(([
      "southwest" : ROOMS"ptrail1",
      "north" : ROOMS"ptrail3",
      ]));
}
