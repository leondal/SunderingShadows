//b53.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway winds gently "+
      "here, leading northwest and southeast.\n");
   set_exits(([
      "northwest" : PATHEXIT"b54",
      "southeast" : PATHEXIT"b52"
   ]));
}