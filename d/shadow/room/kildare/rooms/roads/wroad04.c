//wroad04.c
#include "../../kildare.h"

inherit WHIGH;

void create()
{
   ::create();
   set_exits(([
      "northeast" : ROADS"wroad03",
      "south" : ROADS"wroad05"
      ]));
}
