//eroad03.c
#include "../../kildare.h"

inherit EHIGH;

void create()
{
   ::create();
   set_exits(([
      "southwest" : ROADS"eroad02",
      "southeast" : ROADS"eroad04"
      ]));
}
