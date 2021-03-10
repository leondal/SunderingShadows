//b48.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway turns to the "+
      "northeast, and it opens up into a large chamber south.\n");
   set_exits(([
      "northeast" : PATHEXIT"b47",
      "south" : PATHEXIT"bt9"
   ]));
}