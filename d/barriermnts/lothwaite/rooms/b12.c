//b12.c - Lothwaite barrows.  Circe 4/29/04 
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway descends into "+
      "dimness to the northwest and climbs steadily to the east.\n");
   set_exits(([
      "northwest" : PATHEXIT"b11",
      "east" : PATHEXIT"b13",
   ]));
}