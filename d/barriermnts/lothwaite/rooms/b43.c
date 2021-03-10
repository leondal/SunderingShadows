//b43.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway widens here, "+
      "leading to a more narrow bend north and continuing southeast.\n");
   set_exits(([
      "north" : PATHEXIT"b42",
      "southeast" : PATHEXIT"b44"
   ]));
}