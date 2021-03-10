//b10.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway reaches a sharp "+
      "bend here, leading down to the northeast, and climbing a "+
      "slight incline northwest.  The passageway seems darker here.\n");
   set_exits(([
      "northwest" : PATHEXIT"b9",
      "northeast" : PATHEXIT"b11",
   ]));
}