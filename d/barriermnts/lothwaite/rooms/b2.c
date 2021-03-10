//b2.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The hallway leads south to a large open "+
      "chamber and continues north.\n");
   set_exits(([
      "south" : PATHEXIT"b1",
      "north" : PATHEXIT"b3"
   ]));
}