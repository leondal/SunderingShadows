//b9.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway descends into "+
      "the dimness southeast, and it climbs slightly southwest.\n");
   set_exits(([
      "southwest" : PATHEXIT"b8",
      "southeast" : PATHEXIT"b10",
   ]));
}