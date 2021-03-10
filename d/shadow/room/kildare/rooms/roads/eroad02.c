//eroad02.c
#include "../../kildare.h"

inherit EHIGH;

void create()
{
   ::create();
   set_exits(([
      "northwest" : ROADS"eroad01",
      "northeast" : ROADS"eroad03"
      ]));
}
