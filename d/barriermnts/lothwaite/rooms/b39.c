//b39.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway opens up into "+
      "a grand chamber just north of here and continues straight "+
      "south.\n");
   set_exits(([
      "north" : PATHEXIT"b1",
      "south" : PATHEXIT"b40"
   ]));
}