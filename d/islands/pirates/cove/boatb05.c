#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create(){
   set_monsters(({MON"piratecrew",MON"piratecrew2",MON"piratecrew3"}),({1,2,1}));
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Forecastle");
   set_short("Forecastle");
   set_long("%^BOLD%^Forecastle%^RESET%^\n"
"Up above the main boat's deck is this one, forming the foremost portion of the boat.  From here you have a "
"broad view of the expanse of ocean before the boat, and a fairly good perspective of the rest of the boat "
"behind you.  The prow of the ship leans out over the ocean waves, in the carved shape of a %^RED%^fierce "
"tiger%^RESET%^, eternally suspended mid-leap with claws extended.  The %^ORANGE%^boards %^RESET%^are a "
"little weathered, but have been recently %^WHITE%^%^BOLD%^polished%^RESET%^, and a rail runs along the "
"length of the deck itself, preventing mistaken falls from the side.  Standing in the centre of the deck is "
"the tiller, mounted on a sturdy frame, and stairs lead down from the side of the floor, back toward the "
"main deck.\n");
   set_smell("default","You smell fresh ocean air, lightly spiced with hints of tobacco.");
   set_listen("default","The waves of the ocean lap at the boat's sides.");
   set_items(([
     ({"deck","boards","wooden boards"}):"The wooden boards beneath your feet are a little weathered, but "
"they've obviously been polished recently.",
     "rail":"A low rail runs around the edge of the deck, probably to help stop crewmen from being washed "
"overboard in storms, and as a minor protection against arrows and other missile weapons."
   ]));
   set_exits(([
     "maindeck":COVE"boatb04"
   ]));
}
