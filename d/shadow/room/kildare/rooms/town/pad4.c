//pad4.c
#include "../../kildare.h"

inherit PAD;

void create()
{
   ::create();
   set_exits(([
      "southeast" : TROOMS"pad2",
      "west" : TROOMS"pad5",
      "southwest" : TROOMS"pad6"
      ]));
}
