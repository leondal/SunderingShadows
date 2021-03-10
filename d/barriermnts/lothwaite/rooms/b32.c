//b32.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^A large chamber opens up "+
      "to the southwest, while the wide passageway goes back to "+
      "the east.\n");
   set_exits(([
      "east" : PATHEXIT"b31",
      "southwest" : PATHEXIT"bt3"
   ]));
}