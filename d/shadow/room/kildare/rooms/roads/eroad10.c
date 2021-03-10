//eroad10.c
#include "../../kildare.h"

inherit EMID;

void create()
{
   ::create();
   set_exits(([
      "northeast" : ROADS"eroad09",
      "east" : ROADS"eroad11"
      ]));
}
