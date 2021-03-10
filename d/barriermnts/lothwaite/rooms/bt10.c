//bt10.c - Lothwaite barrows.  Circe 5/1/04 
#include <std.h>
#include "../lothwaite.h"
inherit BTOMB;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BOLD%^%^BLUE%^This impressive "+
      "chamber is situated at the end of the path that leads "+
      "back to the northwest.\n");
   set_exits(([
      "northwest" : PATHEXIT"b50",
   ]));
}