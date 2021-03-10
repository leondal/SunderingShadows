//eroad13.c
#include "../../kildare.h"

inherit EMID;

void create()
{
   ::create();
   set_exits(([
      "south" : ROADS"eroad12",
      "northeast" : ROADS"eroad14"
      ]));
}
