//bt3.c - Lothwaite barrows.  Circe 4/30/04 
#include <std.h>
#include "../lothwaite.h"
inherit BTOMB;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BOLD%^%^BLUE%^The passageway to the "+
      "northeast opens up into this wide chamber.  The chamber becomes "+
      "even more grand further east.\n");
   set_exits(([
      "northeast" : PATHEXIT"b32",
      "east" : PATHEXIT"b33",
   ]));
}