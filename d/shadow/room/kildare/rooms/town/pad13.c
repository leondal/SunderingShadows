//pad13.c
#include "../../kildare.h"

inherit PAD;

void create()
{
   ::create();
   set_exits(([
      "northwest" : TROOMS"pad12",
      "east" : TROOMS"pad14"
      ]));
}
