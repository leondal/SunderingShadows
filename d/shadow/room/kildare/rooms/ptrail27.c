//ptrail27.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   set_exits(([
      "west" : ROOMS"ptrail3",
      "southeast" : ROOMS"ptrail26"
      ]));
}
