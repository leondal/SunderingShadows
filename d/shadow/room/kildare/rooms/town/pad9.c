//pad9.c
#include "../../kildare.h"

inherit PAD;

void create()
{
   ::create();
   set_exits(([
      "northeast" : TROOMS"pad7",
      "north" : TROOMS"pad8",
      "southwest" : TROOMS"pad14"
      ]));
}
