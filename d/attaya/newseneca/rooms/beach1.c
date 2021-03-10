//beach1.c - ~Circe~ 6/15/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"beach";

void create(){
   ::create();
   set_long(::query_long()+"A natural curve in the cliff face here "+
      "blocks further passage west, while the arm of the %^BOLD%^"+
      "%^BLACK%^j%^RESET%^%^ORANGE%^e%^RESET%^t%^BOLD%^t%^BLACK%^y "+
      "%^RESET%^extends northward from the sea to meet it.\n");
   set_exits(([
      "east" : ROOMS"beach2",
      "southwest" : ROOMS"beach5",
      "south" : ROOMS"beach6",
      "southeast" : ROOMS"beach7"
   ]));
}