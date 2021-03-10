//pad7.c
#include "../../kildare.h"

inherit PAD;

void create()
{
   ::create();
   set_exits(([
      "northeast" : TROOMS"pad5",
      "east" : TROOMS"pad6",
      "west" : TROOMS"pad8",
      "southwest" : TROOMS"pad9"
      ]));
}
