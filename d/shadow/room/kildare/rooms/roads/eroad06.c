//eroad06.c
#include "../../kildare.h"

inherit EHIGH;

void create()
{
   ::create();
   set_exits(([
      "west" : ROADS"eroad05",
      "south" : ROADS"eroad07",
        "temple" : "/d/magic/temples/khyron/khyron"
      ]));
}
