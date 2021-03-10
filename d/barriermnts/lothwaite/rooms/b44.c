//b44.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^This passageway widens to the "+
      "east, leading into a grand chamber.  It also continues to the "+
      "northwest.\n");
   set_exits(([
      "east" : PATHEXIT"bt8",
      "northwest" : PATHEXIT"b43"
   ]));
}