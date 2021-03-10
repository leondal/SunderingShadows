#include <std.h>
#include "../seneca.h"

inherit AZUL;

void create()
{
   ::create();
   set_long(::query_long()+"This section of road is very busy, as it is "+
      "the junction of %^YELLOW%^Sol Boulevard %^RESET%^and %^BOLD%^"+
      "%^BLUE%^Azul Avenue%^RESET%^ as well as the entry point into the "+
      "city.  To the north is the large %^ORANGE%^oaken gate %^RESET%^"+
      "reinforced with %^BOLD%^%^BLACK%^iron%^RESET%^ that grants "+
      "entry into the city, while to the south the double lanes of "+
      "%^YELLOW%^Sol Boulevard %^RESET%^travel deeper into the %^BOLD%^"+
      "Seneca%^RESET%^.\n");
   set_exits(([
      "west" : ROOMS"street6",
      "east" : ROOMS"street8",
      "south" : ROOMS"skyline41",
      "north" : ROOMS"town_entry"
   ]));
   set_door("gate","/d/attaya/newseneca/rooms/town_entry","north",0,0);
   set_door_description("gate","%^ORANGE%^To the north is the thick "+
      "%^BOLD%^%^BLACK%^iron-bound %^RESET%^%^ORANGE%^oaken gate that "+
      "grants entry to the city.  It has a very small window with "+
      "%^BOLD%^%^BLACK%^iron bars %^RESET%^%^ORANGE%^but is otherwise "+
      "solid.%^RESET%^");

}
