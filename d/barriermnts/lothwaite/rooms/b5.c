//b5.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The hallway leads west and "+
      "southeast here.\n");
   set_exits(([
      "west" : PATHEXIT"b6",
      "southeast" : PATHEXIT"b4",
   ]));
}