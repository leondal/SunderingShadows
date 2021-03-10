//eroad14.c
#include "../../kildare.h"

inherit ELOW;

void create()
{
   ::create();
   set_exits(([
      "southwest" : ROADS"eroad13",
      "southeast" : ROADS"eroad15"
      ]));
}
