//bt11.c - Lothwaite barrows.  Circe 5/1/04 
#include <std.h>
#include "../lothwaite.h"
inherit BTOMB;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BOLD%^%^BLUE%^This large chamber "+
      "opens up to the south, while it narrows back into the "+
      "passageway to the northeast.\n");
   set_exits(([
      "northeast" : PATHEXIT"b55",
      "south" : PATHEXIT"bt12"
   ]));
}