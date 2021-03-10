//b13.c - Lothwaite barrows.  Circe 4/29/04 
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway descends slightly "+
      "to the west and climbs to the southeast.\n");
   set_exits(([
      "southeast" : PATHEXIT"b14",
      "west" : PATHEXIT"b12",
   ]));
}