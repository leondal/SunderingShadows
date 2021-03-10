//b35.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway winds deeper "+
      "into the mountainside, leading northwest and southeast.\n");
   set_exits(([
      "northwest" : PATHEXIT"b34",
      "southeast" : PATHEXIT"b36"
   ]));
}