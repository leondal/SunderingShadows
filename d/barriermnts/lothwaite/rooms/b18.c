//b18.c - Lothwaite barrows.  Circe 4/29/04 
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway bends here, "+
      "leading southwest and east.\n");
   set_exits(([
      "east" : PATHEXIT"bt1",
      "southwest" : PATHEXIT"b17",
   ]));
}