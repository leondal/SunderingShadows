//b14.c - Lothwaite barrows.  Circe 4/29/04 
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway bends here to the "+
      "northwest and seems to descend that way.  It also continues south.\n");
   set_exits(([
      "northwest" : PATHEXIT"b13",
      "south" : PATHEXIT"b15",
   ]));
}