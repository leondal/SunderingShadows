//b42.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway narrows here "+
      "as it makes a bend into the mountainside, heading east "+
      "and south.\n");
   set_exits(([
      "east" : PATHEXIT"bt7",
      "south" : PATHEXIT"b43"
   ]));
}