//ptrail3.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   set_exits(([
      "northwest" : ROOMS"ptrail4",
      "south" : ROOMS"ptrail2",
      "east" : ROOMS"ptrail27"
      ]));
}
