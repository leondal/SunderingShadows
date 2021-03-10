//bt8.c - Lothwaite barrows.  Circe 5/1/04 
#include <std.h>
#include "../lothwaite.h"
inherit BTOMB;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BOLD%^%^BLUE%^This large chamber is "+
      "at the end of the passageway that leads back west.\n");
   set_exits(([
      "west" : PATHEXIT"b44",
   ]));
}