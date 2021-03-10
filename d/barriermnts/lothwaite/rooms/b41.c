//b41.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway reaches a bend "+
      "here, leading north and into a large chamber southwest.\n");
   set_exits(([
      "north" : PATHEXIT"b40",
      "southwest" : PATHEXIT"bt7"
   ]));
}