//b15.c - Lothwaite barrows.  Circe 4/29/04 
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway continues north "+
      "and west here.\n");
   set_exits(([
      "west" : PATHEXIT"b16",
      "north" : PATHEXIT"b14",
   ]));
}