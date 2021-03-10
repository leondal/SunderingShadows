//pad6.c
#include "../../kildare.h"

inherit PAD;

void create()
{
   ::create();
   set_exits(([
      "northeast" : TROOMS"pad4",
      "north" : TROOMS"pad5",
      "west" : TROOMS"pad7"
      ]));
}
