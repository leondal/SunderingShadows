//pad14.c
#include "../../kildare.h"

inherit PAD;

void create()
{
   ::create();
   set_exits(([
      "northeast" : TROOMS"pad9",
      "west" : TROOMS"pad13"
      ]));
}
