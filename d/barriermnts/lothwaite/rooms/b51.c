//b51.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^This passageway leads west, "+
      "deeper into the mountainside, while it opens into a large "+
      "chamber southeast.\n");
   set_exits(([
      "west" : PATHEXIT"b52",
      "southeast" : PATHEXIT"b1"
   ]));
}