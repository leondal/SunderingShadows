//b55.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway bends here, "+
      "leading east and opening southwest into a large chamber.\n");
   set_exits(([
      "east" : PATHEXIT"b54",
      "southwest" : PATHEXIT"bt11"
   ]));
}