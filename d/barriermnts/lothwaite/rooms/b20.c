//b20.c - Lothwaite barrows.  Circe 4/29/04 
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The normally twisting passageway "+
      "continues strangely straight north and south here.\n");
   set_exits(([
      "south" : PATHEXIT"b19",
      "north" : PATHEXIT"b21",
   ]));
}