//eroad05.c
#include "../../kildare.h"

inherit EHIGH;

void create()
{
   ::create();
   set_exits(([
      "southwest" : ROADS"eroad04",
      "east" : ROADS"eroad06"
      ]));
}
