//b26.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway twists here, "+
      "blocking your view.  It seems to go northwest and southeast.\n");
   set_exits(([
      "southeast" : PATHEXIT"b27",
      "northwest" : PATHEXIT"b25"
   ]));
}