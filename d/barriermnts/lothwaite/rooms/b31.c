//b31.c - Lothwaite barrows.  Circe 4/29/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^Rounding a sharp bend to the "+
      "southeast, the passage continues to the west here.\n");
   set_exits(([
      "west" : PATHEXIT"b32",
      "southeast" : PATHEXIT"b30"
   ]));
}