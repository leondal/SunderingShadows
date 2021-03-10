//pad2.c
#include "../../kildare.h"

inherit PAD;

void create()
{
   ::create();
   set_exits(([
      "east" : TROOMS"pad1",
      "southeast" : TROOMS"pad3",
      "northwest" : TROOMS"pad4"
      ]));
}
