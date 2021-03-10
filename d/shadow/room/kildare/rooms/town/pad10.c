//pad10.c
#include "../../kildare.h"

inherit PAD;

void create()
{
   ::create();
   set_exits(([
      "southeast" : TROOMS"pad8",
      "southwest" : TROOMS"pad11"
      ]));
}
