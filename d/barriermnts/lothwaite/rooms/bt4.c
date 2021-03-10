//bt4.c - Lothwaite barrows.  Circe 4/30/04 
#include <std.h>
#include "../lothwaite.h"
inherit BTOMB;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BOLD%^%^BLUE%^This wide chamber "+
      "dwarfs the already broad passageway.  The passageway itself "+
      "is to the northwest, while the chamber opens further east.\n");
   set_exits(([
      "northwest" : PATHEXIT"b38",
      "east" : PATHEXIT"bt5",
   ]));
}