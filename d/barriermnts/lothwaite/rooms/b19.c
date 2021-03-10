//b19.c - Lothwaite barrows.  Circe 4/29/04 
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^Just southwest of here, the "+
      "passageway bends out of sight, while it continues straight "+
      "to the north.\n");
   set_exits(([
      "southwest" : PATHEXIT"bt1",
      "north" : PATHEXIT"b20",
   ]));
}