//ptrail6.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   set_exits(([
      "southwest" : ROOMS"ptrail4",
      "north" : ROOMS"ptrail7"
      ]));
}
