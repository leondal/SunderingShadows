//shore7.c - ~Circe~ 6/18/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"shore.c";

void create(){
   ::create();
   set_long(::query_long()+"\nThis section of the shore "+
      "runs up against the arm of the %^BOLD%^"+
      "%^BLACK%^j%^RESET%^%^ORANGE%^e%^RESET%^t%^BOLD%^t%^BLACK%^y"+
      "%^RESET%^, which extends from the sea and runs northward to "+
      "meet the face of the cliff.\n");
   set_exits(([
      "northwest" : ROOMS"beach10",
      "north" : ROOMS"beach11",
      "west" : ROOMS"shore6"
   ]));
}