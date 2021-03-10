//b24.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^Strangely, the normally winding "+
      "passageway runs straight east and west here.\n");
   set_exits(([
      "east" : PATHEXIT"b25",
      "west" : PATHEXIT"b23"
   ]));
}