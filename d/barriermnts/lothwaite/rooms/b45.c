//b45.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The archway to the northeast "+
      "leads into a large chamber, while the passageway continues "+
      "southwest.\n");
   set_exits(([
      "northeast" : PATHEXIT"b1",
      "southwest" : PATHEXIT"b46"
   ]));
}