//b30.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^A sharp bend in the passage here "+
      "causes it to lead both southwest and northwest.\n");
   set_exits(([
      "northwest" : PATHEXIT"b31",
      "southwest" : PATHEXIT"b29"
   ]));
}