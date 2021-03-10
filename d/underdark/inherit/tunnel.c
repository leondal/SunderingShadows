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
   set_name("A dark tunnel");
   set_short("%^BOLD%^%^BLACK%^A dark tunnel%^RESET%^");
   set_long("%^BLUE%^Solid %^WHITE%^rock %^BLUE%^frames this narrow tunnel that leads downwards into "
"%^BOLD%^%^BLACK%^darkness%^RESET%^%^BLUE%^.  It is only wide enough for two people to walk abreast, with its "
"length impossible to discern due to the way it curves.  The %^WHITE%^stone walls%^BLUE%^, at least, are "
"smooth enough that no snags of stone catch at your hair or clothing.  It is unusually %^ORANGE%^tidy%^BLUE%^ "
"also, with very little dust or stray stones under your feet, making your travel here quite easy.%^RESET%^");
   set_smell("default","The smell of damp stone fills the air.");
   set_listen("default","It is very quiet and still here.");
   set_items(([
     ({"walls","roof","ceiling","floor","rock","stone"}):"%^BLUE%^Solid %^WHITE%^stone %^BLUE%^frames this "
"narrow tunnel.  Oddly, no snags of rock protrude from the walls, and no %^ORANGE%^dust %^BLUE%^or stray "
"%^BOLD%^%^BLACK%^stones %^RESET%^%^BLUE%^tumble underfoot.  Certainly, the wear and tear of weather has no "
"effect this far underground.%^RESET%^",
   ]));
}
