//bt9.c - Lothwaite barrows.  Circe 5/1/04 
#include <std.h>
#include "../lothwaite.h"
inherit BTOMB;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BOLD%^%^BLUE%^This large chamber "+
      "has been carved from the mountain, a widening of the "+
      "passages that continue both north and southwest.\n");
   set_exits(([
      "north" : PATHEXIT"b48",
      "southwest" : PATHEXIT"b49"
   ]));
}