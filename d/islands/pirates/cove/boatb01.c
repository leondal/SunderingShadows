#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create(){
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Poop deck");
   set_short("Poop deck");
   set_long("%^BOLD%^Poop deck%^RESET%^\n"
"This is the aftermost and highest deck, called the poop deck, an addition to more modern vessel designs.  "
"It allows a clear view of the entire boat, as well as a great range of what surrounds the vessel.  The "
"%^ORANGE%^boards %^RESET%^are a little weathered, but have been recently %^WHITE%^%^BOLD%^polished%^RESET%^"
", and a rail runs around the length of the deck itself, preventing mistaken falls from the side.  Directly "
"below this deck is the quarterdeck, which allows access to both the ship's remaining decks, and to land via "
"the gangplank when the ship is docked.\n");
   set_smell("default","You smell fresh ocean air, lightly spiced with hints of tobacco.");
   set_listen("default","The waves of the ocean lap at the boat's sides.");
   set_items(([
     ({"deck","boards","wooden boards"}):"The wooden boards beneath your feet are a little weathered, but "
"they've obviously been polished recently.",
     "rail":"A low rail runs around the edge of the deck, probably to help stop crewmen from being washed "
"overboard in storms, and as a minor protection against arrows and other missile weapons."
   ]));
   set_exits(([
     "quarterdeck":COVE"boatb02"
   ]));
}

void reset() {
   if(!has_mobs()) {
     if(mons) mons = ([]);
     switch(random(3)) {
       case 0:
       set_monsters(({MON"mage",MON"piratecrew2"}),({1,2}));
       break;
       case 1:
       set_monsters(({MON"mage",MON"piratecrew",MON"piratecrew2"}),({1,1,1}));
       break;
       case 2:
       set_monsters(({MON"mage",MON"piratecrew"}),({1,2}));
       break;
     }
   }
   ::reset();
}
