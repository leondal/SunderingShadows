//eroad08.c
#include "../../kildare.h"

inherit EHIGH;

void create()
{
   ::create();
   set_exits(([
      "northeast" : ROADS"eroad07",
      "southwest" : ROADS"eroad09"
      ]));
}
