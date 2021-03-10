//wroad05.c
#include "../../kildare.h"

inherit WHIGH;

void create()
{
   ::create();
   set_exits(([
      "north" : ROADS"wroad04",
      "south" : ROADS"wroad06"
      ]));
}
