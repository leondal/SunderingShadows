//eroad11.c
#include "../../kildare.h"

inherit EMID;

void create()
{
   ::create();
   set_exits(([
      "west" : ROADS"eroad10",
      "southeast" : ROADS"eroad12"
      ]));
}
