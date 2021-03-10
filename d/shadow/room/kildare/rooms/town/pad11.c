//pad11.c
#include "../../kildare.h"

inherit PAD;

void create()
{
   ::create();
   set_exits(([
      "northeast" : TROOMS"pad10",
      "southwest" : TROOMS"pad12"
      ]));
}
