//eroad09.c
#include "../../kildare.h"

inherit EMID;

void create()
{
   ::create();
   set_exits(([
      "northeast" : ROADS"eroad08",
      "southwest" : ROADS"eroad10"
      ]));
}
