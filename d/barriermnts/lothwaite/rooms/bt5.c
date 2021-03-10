//bt5.c - Lothwaite barrows.  Circe 4/30/04 
#include <std.h>
#include "../lothwaite.h"
inherit BTOMB;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BOLD%^%^BLUE%^This massive chamber "+
      "opens back west and curves slightly to the northeast.\n");
   set_exits(([
      "west" : PATHEXIT"bt4",
      "northeast" : PATHEXIT"bt6",
   ]));
}