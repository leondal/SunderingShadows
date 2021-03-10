//eroad04.c
#include "../../kildare.h"

inherit EHIGH;

void create()
{
   ::create();
   set_exits(([
      "northwest" : ROADS"eroad03",
      "northeast" : ROADS"eroad05"
      ]));
}
