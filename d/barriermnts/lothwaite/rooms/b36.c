//b36.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway bends to the "+
      "northwest here as well as leading south.\n");
   set_exits(([
      "northwest" : PATHEXIT"b35",
      "south" : PATHEXIT"b37"
   ]));
}