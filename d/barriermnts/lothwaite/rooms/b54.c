//b54.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway leads to the "+
      "west and curves back around to the southeast.\n");
   set_exits(([
      "west" : PATHEXIT"b55",
      "southeast" : PATHEXIT"b53"
   ]));
}