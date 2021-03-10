//b37.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^A straight portion of the "+
      "normally twisting passageway leads north, and the passage "+
      "also rounds a bend to the southwest.\n");
   set_exits(([
      "north" : PATHEXIT"b36",
      "southwest" : PATHEXIT"b38"
   ]));
}