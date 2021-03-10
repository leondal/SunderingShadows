//shore1.c - Shore of Loch Tearmann.  Circe 9/11/04
#include <std.h>
#include "../lothwaite.h"
inherit LOTHSHORE;

void create(){
   ::create();
   set_long( ::query_long()+"Up the hill to the south, you can see "+
      "the towering %^ORANGE%^grainery%^GREEN%^, and a tall %^RESET%^"+
      "weeping willow %^GREEN%^stands here, "+
      "its droopy branches dancing upon the wind as it provides "+
      "%^BOLD%^%^BLACK%^shade %^RESET%^%^GREEN%^to those reclining "+
      "here.\n");
   add_item("willow","The ancient willow tree sways in the wind.  It "+
      "looks to have been here for centuries, and its graceful branches "+
      "truly look to be dancing to the wind's melody.");
   add_item("weeping willow","The ancient willow tree sways in the wind.  It "+
      "looks to have been here for centuries, and its graceful branches "+
      "truly look to be dancing to the wind's melody.");
   add_item("grainery","The wooden silo stands tall against the "+
      "horizon, a testament to the farming ability of the citizens "+
      "of Lothwaite despite the somewhat harsh conditions of the "+
      "mountain at times.");
   set_exits(([
      "west" : PATHEXIT"dock",
      "southeast" : PATHEXIT"shore2"
   ]));
}