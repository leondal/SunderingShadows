//b28.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^Just to the southwest, there "+
      "seems to be a bend in the passageway, while it continues "+
      "relatively straight to the northeast.\n");
   set_exits(([
      "northeast" : PATHEXIT"b29",
      "southwest" : PATHEXIT"b27"
   ]));
}