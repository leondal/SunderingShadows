//b22.c - Lothwaite barrows.  Circe 4/29/04 
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway leads a short "+
      "distance to the west before turning a corner, and it opens "+
      "up to a larger chamber southeast.\n");
   set_exits(([
      "southeast" : PATHEXIT"bt2",
      "west" : PATHEXIT"b21",
   ]));
}