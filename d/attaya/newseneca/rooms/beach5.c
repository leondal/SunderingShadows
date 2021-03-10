//beach5.c - ~Circe~ 6/15/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"beach";

void create(){
   ::create();
   set_long(::query_long()+"This section of the beach runs up "+
      "against the arm of the %^BOLD%^"+
      "%^BLACK%^j%^RESET%^%^ORANGE%^e%^RESET%^t%^BOLD%^t%^BLACK%^y"+
      "%^RESET%^, which extends from the sea and runs northward to "+
      "meet the face of the cliff.\n");
   set_exits(([
      "northeast" : ROOMS"beach1",
      "east" : ROOMS"beach6",
      "south" : ROOMS"shore1",
      "southeast" : ROOMS"shore2"
   ]));
}