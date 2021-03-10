//b46.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway twists and "+
      "turns, leading west and northeast.\n");
   set_exits(([
      "west" : PATHEXIT"b47",
      "northeast" : PATHEXIT"b45"
   ]));
}