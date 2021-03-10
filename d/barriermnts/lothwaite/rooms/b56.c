//b56.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^A wide, impressive chamber "+
      "opens to the northwest, and the more narrow passageway "+
      "continues east.\n");
   set_exits(([
      "east" : PATHEXIT"b57",
      "northwest" : PATHEXIT"bt12"
   ]));
}