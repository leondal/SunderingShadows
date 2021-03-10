//ptrail25.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   set_exits(([
      "northwest" : ROOMS"ptrail24"
      ]));
}
