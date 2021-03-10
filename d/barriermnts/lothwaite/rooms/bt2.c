//bt2.c - Lothwaite barrows.  Circe 4/30/04 
#include <std.h>
#include "../lothwaite.h"
inherit BTOMB;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BOLD%^%^BLUE%^This chamber opens "+
      "out at the end of the passageway that leads back to the "+
      "northwest.\n");
   set_exits(([
      "northwest" : PATHEXIT"b22",
   ]));
}