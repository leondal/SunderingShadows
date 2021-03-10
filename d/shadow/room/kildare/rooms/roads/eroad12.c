//eroad12.c
#include "../../kildare.h"

inherit EMID;

void create()
{
   ::create();
   set_exits(([
      "northwest" : ROADS"eroad11",
      "north" : ROADS"eroad13"
      ]));
}
