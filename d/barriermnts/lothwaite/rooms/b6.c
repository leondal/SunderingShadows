//b6.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The hallway leads east and "+
      "northwest here, twisting deeper into the mountainside.\n");
   set_exits(([
      "northwest" : PATHEXIT"b7",
      "east" : PATHEXIT"b5",
   ]));
}