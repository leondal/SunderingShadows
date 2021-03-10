//b40.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The normally twisting passageway "+
      "runs straight north and south here.\n");
   set_exits(([
      "north" : PATHEXIT"b39",
      "south" : PATHEXIT"b41"
   ]));
}