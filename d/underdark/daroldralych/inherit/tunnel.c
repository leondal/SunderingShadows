#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",0);
   set_property("indoors",1);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_terrain(NAT_CAVE);
   set_travel(PAVED_ROAD);
   set_name("A narrow tunnel");
   set_short("%^BOLD%^%^BLACK%^A narrow tunnel%^RESET%^");
   set_smell("default","The air is crisp and clear here, despite the enclosed cavern surroundings.");
   set_listen("default","The distant murmurs of a busy city echo from down the corridor.");
   set_items(([
     ({"walls","floor","roof","cavern"}):"%^BOLD%^%^BLACK%^The cavern is formed entirely of %^RESET%^%^WHITE%^"
"dull stone%^BOLD%^%^BLACK%^, obviously artificially formed, but only roughly so.  Loose rocks and rubble are "
"collected at the sides of the passageway, swept aside by the passing of many feet.%^RESET%^",
     ({"dust","rubble","rocks"}):"%^BOLD%^%^BLACK%^Small piles of rubble and rocks have collected at either "
"side of the pathway, probably swept aside by the passing of many feet.%^RESET%^",
   ]));
}
