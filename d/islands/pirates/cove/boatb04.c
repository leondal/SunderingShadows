#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create(){
   set_monsters(({MON"piratecrew",MON"piratecrew2",MON"piratecrew3"}),({1,1,1}));
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Main deck");
   set_short("Main deck");
   set_long("%^BOLD%^Main deck%^RESET%^\n"
"This deck forms the central point of the ship, and is the largest of all the boat's decks.  The three masts "
"reach up to the sky from the wooden boarding beneath your feet, trailing ratlines to the crow's nest "
"above.  The %^ORANGE%^boards %^RESET%^are a little weathered, but have been recently %^WHITE%^%^BOLD%^"
"polished%^RESET%^, and a rail runs along the length of the deck itself, preventing mistaken falls from the "
"side.  A few crates and barrels are standing around, though they have been placed out of the main "
"thoroghfare.  This deck is usually the most active, with pirates going to and fro about their business.  A "
"wide corridor leads beneath the forecastle, allowing access to the sleeping cabins.\n");
   set_smell("default","You smell fresh ocean air, lightly spiced with hints of tobacco.");
   set_listen("default","The waves of the ocean lap at the boat's sides.");
   set_items(([
     ({"ratlines","masts","mast","crows nest","crow's nest"}):"Three solid masts rise up from the wooden "
"boarding at your feet, reaching up toward the sky above.  Ratlines trail down from the crow's nest at the "
"very top.",
     ({"deck","boards","wooden boards"}):"The wooden boards beneath your feet are a little weathered, but "
"they've obviously been polished recently.",
     "rail":"A low rail runs around the edge of the deck, probably to help stop crewmen from being washed "
"overboard in storms, and as a minor protection against arrows and other missile weapons."
   ]));
   set_exits(([
     "cabins":COVE"boatb06",
     "forecastle":COVE"boatb05",
     "west":COVE"boatb03"
   ]));
}
