//b16.c - Lothwaite barrows.  Circe 4/29/04 
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway leads east and "+
      "southwest here.\n");
   set_exits(([
      "east" : PATHEXIT"b15",
      "southwest" : PATHEXIT"b4",
   ]));
}