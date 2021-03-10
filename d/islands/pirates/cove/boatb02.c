#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create(){
   set_monsters(({MON"piratecrew",MON"piratecrew2"}),({1,1}));
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Quarter deck");
   set_short("Quarter deck");
   set_long("%^BOLD%^Quarter deck%^RESET%^\n"
"You've approached the rear of this pirate boat.  The vessel is of a more modern design, with a gangplank "
"secured upon this deck, to allow passage to land at times when the boat is docked.  The %^ORANGE%^boards "
"%^RESET%^are a little weathered, but have been recently %^WHITE%^%^BOLD%^polished%^RESET%^, and a rail runs "
"around the length of the deck itself, preventing mistaken falls from the side.  Above this floor is the "
"poop deck, furthest to the rear of the boat, while down the stairs is the ship's main deck.\n");
   set_smell("default","You smell fresh ocean air, lightly spiced with hints of tobacco.");
   set_listen("default","The waves of the ocean lap at the boat's sides.");
   set_items(([
     ({"deck","boards","wooden boards"}):"The wooden boards beneath your feet are a little weathered, but "
"they've obviously been polished recently.",
     "rail":"A low rail runs around the edge of the deck, probably to help stop crewmen from being washed "
"overboard in storms."
   ]));
   set_exits(([
     "dock":COVE"dock7",
     "maindeck":COVE"boatb03",
     "poopdeck":COVE"boatb01"
   ]));
   find_object_or_load(COVE"dock7");
}
