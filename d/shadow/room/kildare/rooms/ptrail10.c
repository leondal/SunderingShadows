//ptrail10.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   set_exits(([
      "southeast" : ROOMS"ptrail9",
      "west" : ROOMS"ptrail11"
      ]));
}
