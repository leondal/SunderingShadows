//b52.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passage bends slowly here, "+
      "leading both east and northwest.\n");
   set_exits(([
      "east" : PATHEXIT"b51",
      "northwest" : PATHEXIT"b53"
   ]));
}