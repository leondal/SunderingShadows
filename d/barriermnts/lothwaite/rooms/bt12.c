//bt12.c - Lothwaite barrows.  Circe 5/2/04 
#include <std.h>
#include "../lothwaite.h"
inherit BTOMB;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BOLD%^%^BLUE%^This large chamber "+
      "opens up to the north, while it narrows back into the "+
      "passageway to the southeast.\n");
   set_exits(([
      "southeast" : PATHEXIT"b56",
      "north" : PATHEXIT"bt11"
   ]));
}