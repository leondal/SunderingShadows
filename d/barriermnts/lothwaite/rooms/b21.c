//b21.c - Lothwaite barrows.  Circe 4/29/04 
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^A sharp bend in the passageway "+
      "here leads south or deeper into the mountains east.\n");
   set_exits(([
      "south" : PATHEXIT"b20",
      "east" : PATHEXIT"b22",
   ]));
}