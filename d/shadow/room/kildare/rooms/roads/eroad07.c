//eroad07.c
#include "../../kildare.h"

inherit EHIGH;

void create()
{
   ::create();
   set_exits(([
      "north" : ROADS"eroad06",
      "southwest" : ROADS"eroad08"
      ]));
}
