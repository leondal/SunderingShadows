//ptrail24.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   set_exits(([
      "southwest" : ROOMS"ptrail26",
      "southeast" : ROOMS"ptrail25",
      "northeast" : ROOMS"ptrail23"
      ]));
}
