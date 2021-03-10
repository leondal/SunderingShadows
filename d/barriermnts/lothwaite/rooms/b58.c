//b58.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The normally twisting "+
      "passageway leads relatively straight east and west here.\n");
   set_exits(([
      "east" : PATHEXIT"b59",
      "west" : PATHEXIT"b57"
   ]));
}