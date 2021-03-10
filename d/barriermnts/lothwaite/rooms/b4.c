//b4.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The hallway leads south here, "+
      "and forks just to the north, with passages going northeast and "+
      "northwest.\n");
   set_exits(([
      "south" : PATHEXIT"b3",
      "northwest" : PATHEXIT"b5",
      "northeast" : PATHEXIT"b16"
   ]));
}