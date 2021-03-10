//shore3.c - Shore of Loch Tearmann.  Circe 9/11/04
#include <std.h>
#include "../lothwaite.h"
inherit LOTHSHORE;

void create(){
   ::create();
   set_long( ::query_long()+"A large %^RESET%^boulder %^GREEN%^"+
      "stands here, a spur from the mountain itself.  It has "+
      "been worn smooth over the ages, and it now has several "+
      "%^CYAN%^runic symbols %^GREEN%^carved into it.\n");
   add_item("boulder","This worn boulder has stood here for ages and "+
      "is quite weather-beaten.  There are strange runic symbols "+
      "carved on it in various places.");
   add_item("symbols","The symbols seem to have no meaning any more.");
   add_item("runic symbols","The symbols seem to have no meaning any more.");
   set_exits(([
      "west" : PATHEXIT"shore2",
      "east" : PATHEXIT"shore4"
   ]));
}