//b50.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^Here at a bend in the "+
      "passageway, the path continues northeast, while a large "+
      "chamber opens up southeast.\n");
   set_exits(([
      "northeast" : PATHEXIT"b49",
      "southeast" : PATHEXIT"bt10"
   ]));
}