//k_road01.c - First room for the road to the new Koenig - coded by Circe 10/3/03
#include <std.h>
#include "../koenig.h"
inherit KROAD;

void create() {
   ::create();
   set_exits(([
      "northwest" : "/d/shadow/room/forest/road21",
      "southeast" : VILROOMS"k_road02"
   ]));
}