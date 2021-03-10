//k_road02.c - Road to the new Koenig - coded by Circe 10/3/03
#include <std.h>
#include "../koenig.h"
inherit KROAD;

void create() {
   ::create();
   set_exits(([
      "northwest" : VILROOMS"k_road01",
      "east" : VILROOMS"k_road03"
   ]));
}