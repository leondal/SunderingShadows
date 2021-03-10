//b27.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^A sharp bend in the passageway "+
      "here causes it to lead both northwest and northeast.\n");
   set_exits(([
      "northeast" : PATHEXIT"b28",
      "northwest" : PATHEXIT"b26"
   ]));
}