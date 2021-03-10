//ptrail26.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   set_exits(([
      "northwest" : ROOMS"ptrail27",
      "northeast" : ROOMS"ptrail24"
      ]));
}
