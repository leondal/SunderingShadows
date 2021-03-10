//sstreet30 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VERDE;

void create(){
   ::create();
   set_long(::query_long()+"An aged %^BOLD%^%^BLACK%^iron picket "+
      "fence %^RESET%^borders the road on the north, giving you a "+
      "glimpse of the %^BOLD%^%^BLACK%^cemetery %^RESET%^beyond.\n");
   set_exits(([
      "east" : ROOMS"sstreet29",
      "northwest" : ROOMS"sstreet31",
      "north" : ROOMS"cemetery"
   ]));
   set_door("gate","/d/attaya/newseneca/rooms/cemetery","north",0,0);
   set_door_description("gate","%^BOLD%^%^BLACK%^The gate is made of "+
      "iron bars much like the rest of the fence.  It features decorative "+
      "caps in the shape of fleurs-de-lis and has a simple handle.%^RESET%^");
   add_item("fence","%^BOLD%^%^BLACK%^The picket fence is crafted from iron "+
      "and has slender bars topped with decorative fleurs-de-lis.  It "+
      "encloses the cemetery to the north, broken only by the gate.%^RESET%^");
   add_item("cemetery","%^GREEN%^The grassy cemetery is well-tended and "+
      "has %^RESET%^markers %^GREEN%^of all types.%^RESET%^");
}