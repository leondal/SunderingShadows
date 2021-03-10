//k_road04.c - Road to the new Koenig - coded by Circe 10/3/03
#include <std.h>
#include "../koenig.h"
inherit KROAD;

void create() {
   ::create();
   set_exits(([
      "west" : VILROOMS"k_road03",
      "northeast" : VILROOMS"k_road05"
   ]));
}