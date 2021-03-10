//pad8.c
#include "../../kildare.h"

inherit PAD;

void create()
{
   ::create();
   set_exits(([
      "northwest" : TROOMS"pad10",
      "east" : TROOMS"pad7",
      "south" : TROOMS"pad9"
      ]));
}
