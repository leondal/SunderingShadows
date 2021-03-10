//bt1.c - Lothwaite barrows.  Circe 4/30/04 
#include <std.h>
#include "../lothwaite.h"
inherit BTOMB;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BOLD%^%^BLUE%^This chamber narrows "+
      "on the western end, leading into a passage there.  It curves "+
      "around the corner northeast.\n");
   set_exits(([
      "northeast" : PATHEXIT"b19",
      "west" : PATHEXIT"b18",
   ]));
}