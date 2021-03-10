//b7.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The passageway leads northwest "+
      "and southeast here as it begins to descend steadily.\n");
   set_exits(([
      "northwest" : PATHEXIT"b8",
      "southeast" : PATHEXIT"b6",
   ]));
}