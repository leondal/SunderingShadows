//ptrail12.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   set_exits(([
      "southwest" : ROOMS"ptrail9",
      "north" : ROOMS"ptrail13"
      ]));
}
