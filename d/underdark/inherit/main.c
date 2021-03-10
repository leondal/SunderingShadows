#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   if(!random(4)) set_property("no teleport",1);
   set_terrain(NAT_CAVE);
   set_travel(PAVED_ROAD);
   set_name("A broad underground tunnel");
   set_short("%^BLUE%^A broad underground tunnel%^RESET%^");
   set_long("%^ORANGE%^Solid %^WHITE%^rock %^ORANGE%^frames this broad tunnel "
"that leads directly east-west in a straight line.  It is oddly precise in "
"its formation, and feels to be perfectly flat-level, as if it were made by "
"mortal hands.  It is easily wide enough for two carts to travel side by "
"side, or many creatures abreast, with the roof far enough up that it would "
"not bother even a giant traveller.  The stone walls are unusually %^RED%^"
"smooth%^ORANGE%^, with very few snags or protrusions.  The tunnel floor is "
"also remarkably clear, with very little %^WHITE%^dust %^ORANGE%^or %^BOLD%^"
"%^BLACK%^stray stones %^RESET%^%^ORANGE%^under your feet.  Travel along this "
"tunnel would be particularly easy.%^RESET%^");
   set_smell("default","The smell of damp stone fills the air.");
   set_listen("default","It is very quiet and still here.");
   set_items(([
     ({"walls","roof","ceiling","floor","rock","stone"}):"%^ORANGE%^Solid "
"%^WHITE%^stone %^ORANGE%^frames this narrow tunnel.  Oddly, no snags or "
"protrusions of rock jut out from the walls, and no %^WHITE%^dust %^ORANGE%^"
"or %^BOLD%^%^BLACK%^stray stones %^RESET%^%^ORANGE%^tumble underfoot.  "
"Certainly, the wear and tear of %^BLUE%^weather %^ORANGE%^has no effect this "
"far underground.%^RESET%^",
   ]));
}
