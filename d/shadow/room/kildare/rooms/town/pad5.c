//pad5.c
#include "../../kildare.h"

inherit PAD;

void create()
{
   ::create();
   set_exits(([
      "east" : TROOMS"pad4",
      "south" : TROOMS"pad6",
      "southwest" : TROOMS"pad7"
      ]));
}
