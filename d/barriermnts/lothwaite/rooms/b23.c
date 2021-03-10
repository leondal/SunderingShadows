//b23.c - Lothwaite barrows.  Circe 4/30/04 
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^A large main chamber seems to "+
      "open up to the west, while the passage continues straight east "+
      "for awhile as well.\n");
   set_exits(([
      "west" : PATHEXIT"b1",
      "east" : PATHEXIT"b24"
   ]));
}