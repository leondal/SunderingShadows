//b8.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway bends sharply "+
      "here, with a slight incline heading southeast while a decline "+
      "leads into the darkness northeast.\n");
   set_exits(([
      "northeast" : PATHEXIT"b9",
      "southeast" : PATHEXIT"b7",
   ]));
}