//eroad15.c
#include "../../kildare.h"

inherit ELOW;

void create()
{
   ::create();
   set_exits(([
      "northwest" : ROADS"eroad14",
      "southeast" : "/d/shadow/room/forest/owagon40"
      ]));
}
