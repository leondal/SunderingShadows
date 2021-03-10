//b49.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^A grand chamber opens here "+
      "to the northeast, while the passageway continues winding "+
      "beneath the mountain southwest.\n");
   set_exits(([
      "northeast" : PATHEXIT"bt9",
      "southwest" : PATHEXIT"b50"
   ]));
}