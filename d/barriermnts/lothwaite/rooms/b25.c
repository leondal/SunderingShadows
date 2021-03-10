//b25.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passage runs straight "+
      "west here, and it rounds a bend to the southeast.\n");
   set_exits(([
      "southeast" : PATHEXIT"b26",
      "west" : PATHEXIT"b24"
   ]));
}