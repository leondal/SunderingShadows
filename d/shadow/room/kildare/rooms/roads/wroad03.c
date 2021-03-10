//wroad03.c
#include "../../kildare.h"

inherit WHIGH;

void create()
{
   ::create();
   set_exits(([
      "northeast" : ROADS"wroad02",
      "southwest" : ROADS"wroad04"
      ]));
}
