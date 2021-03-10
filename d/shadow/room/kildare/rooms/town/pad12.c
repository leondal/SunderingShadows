//pad12.c
#include "../../kildare.h"

inherit PAD;

void create()
{
   ::create();
   set_exits(([
      "northeast" : TROOMS"pad11",
      "southeast" : TROOMS"pad13",
      "southwest" : ROADS"wroad01"
      ]));
}
