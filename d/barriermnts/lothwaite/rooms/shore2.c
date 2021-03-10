//shore2.c - Shore of Loch Tearmann.  Circe 9/11/04
#include <std.h>
#include "../lothwaite.h"
inherit LOTHSHORE;

void create(){
   ::create();
   set_long( ::query_long()+"Up the hill to the southwest, you can see "+
      "the towering %^ORANGE%^grainery%^GREEN%^.\n");
   add_item("grainery","The wooden silo stands tall against the "+
      "horizon, a testament to the farming ability of the citizens "+
      "of Lothwaite despite the somewhat harsh conditions of the "+
      "mountain at times.");
   set_exits(([
      "east" : PATHEXIT"shore3",
      "northwest" : PATHEXIT"shore1"
   ]));
}