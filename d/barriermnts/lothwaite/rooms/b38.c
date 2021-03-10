//b38.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^Here, the passageway bends "+
      "sharply, leading both northeast and southeast.\n");
   set_exits(([
      "northeast" : PATHEXIT"b37",
      "southeast" : PATHEXIT"bt4"
   ]));
}