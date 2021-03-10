//b17.c - Lothwaite barrows.  Circe 4/29/04 
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway southwest into a "+
      "large, open chamber as well as delving further into the mountain "+
      "northeast.\n");
   set_exits(([
      "northeast" : PATHEXIT"b18",
      "southwest" : PATHEXIT"b1",
   ]));
}