//bt6.c - Lothwaite barrows.  Circe 4/30/04 
#include <std.h>
#include "../lothwaite.h"
inherit BTOMB;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BOLD%^%^BLUE%^This impressive chamber "+
      "ends here and opens out further southwest.\n");
   set_exits(([
      "southwest" : PATHEXIT"bt5",
   ]));
}