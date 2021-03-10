//b47.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway bends here, "+
      "leading east and southwest.\n");
   set_exits(([
      "east" : PATHEXIT"b46",
      "southwest" : PATHEXIT"b48"
   ]));
}