//viento53 - Circe 11/11/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VIENTO;

void create(){
   ::create();
   set_long(::query_long()+"This stretch of road leads to the %^BOLD%^"+
      "town square %^RESET%^to the east.  North and south of here are "+
      "%^GREEN%^gardens %^RESET%^with grand monuments set among stone "+
      "benches.\n");
   set_exits(([
      "west" : ROOMS"viento52",
      "east" : ROOMS"square",
      "north" : ROOMS"monument1",
      "south" : ROOMS"monument4"
   ]));
}