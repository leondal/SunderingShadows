//shore4.c - Shore of Loch Tearmann.  Circe 9/11/04
#include <std.h>
#include "../lothwaite.h"
inherit LOTHSHORE;

void create(){
   ::create();
   set_long( ::query_long()+"Several tall %^RESET%^"+
      "weeping willows %^GREEN%^stand here, "+
      "their droopy branches dancing upon the wind as they provide "+
      "%^BOLD%^%^BLACK%^shade %^RESET%^%^GREEN%^to those reclining "+
      "here.\n");
   add_item("willow","These ancient willow trees sway in the wind.  They "+
      "look to have been here for centuries, and their graceful branches "+
      "truly look to be dancing to the wind's melody.");
   add_item("willows","These ancient willow trees sway in the wind.  They "+
      "look to have been here for centuries, and their graceful branches "+
      "truly look to be dancing to the wind's melody.");
   add_item("weeping willows","These ancient willow trees sway in the wind.  They "+
      "look to have been here for centuries, and their graceful branches "+
      "truly look to be dancing to the wind's melody.");
   set_exits(([
      "west" : PATHEXIT"shore3",
      "east" : PATHEXIT"shore5"
   ]));
}