//b34.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^A large, open chamber opens "+
      "up to the northwest, and the passage continues southeast.\n");
   set_exits(([
      "northwest" : PATHEXIT"b1",
      "southeast" : PATHEXIT"b35"
   ]));
}