//b29.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway winds gently here, "+
      "allowing you to see some distance both northeast and southwest.\n");
   set_exits(([
      "northeast" : PATHEXIT"b30",
      "southwest" : PATHEXIT"b28"
   ]));
}