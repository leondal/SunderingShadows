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
   set_name("An underground mining tunnel");
   set_short("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^");
   set_long("%^BLUE%^You stand within the lower reaches of the mine system.  "
"The air is thick and %^RED%^humid %^BLUE%^here among the darker stone "
"tunnels, which have obviously been made by mortal hands.  %^ORANGE%^Heavy "
"wooden beams %^BLUE%^and %^WHITE%^metal bars %^BLUE%^support the stone of "
"the walls and roof, from which glitter specks of %^CYAN%^ge%^BOLD%^m"
"%^WHITE%^st%^CYAN%^o%^RESET%^%^CYAN%^ne %^BLUE%^and seams of precious "
"%^WHITE%^me%^BOLD%^t%^RESET%^%^WHITE%^als%^BLUE%^, only waiting to be "
"extracted from their rocky prison.  Along the ground, a pair of "
"%^BOLD%^%^BLACK%^thick metal rails %^RESET%^%^BLUE%^has been placed, perhaps "
"to carry mining carts back and forth.%^RESET%^");
   set_smell("default","The air is a little more damp here, and carries a metallic tinge.");
   set_listen("default","The occasional sound of metal on stone reaches your ears.");
   set_items(([
     ({"walls","roof","ceiling","rock","stone","tunnel"}):"%^BLUE%^This "
"tunnel has obviously been made by mortal hands, cut directly into the heavy "
"rock of the deeper mountains.%^RESET%^",
     ({"bars","beams"}):"%^RED%^Heavy wooden beams %^BLUE%^ and bars of "
"%^WHITE%^dull metal%^BLUE%^ provide support to the tunnel at regular "
"intervals.",
     ({"metal","gemstones","seams"}):"%^BLUE%^Specks of precious%^CYAN%^ "
"ge%^BOLD%^m%^WHITE%^st%^CYAN%^o%^RESET%^%^CYAN%^ne %^BLUE%^and seams of "
"lustrous %^WHITE%^me%^BOLD%^t%^RESET%^%^WHITE%^als%^BLUE%^ glitter from "
"within the rocky walls of the tunnel.%^RESET%^",
     ({"rails","ground","floor"}):"%^BLUE%^A pair of %^BOLD%^%^BLACK%^thick "
"metal rails %^RESET%^%^BLUE%^run the length of the tunnel, disappearing into "
"darkness at either end.  Presumably they are designed to carry mining carts "
"back and forth.%^RESET%^",
   ]));
}
