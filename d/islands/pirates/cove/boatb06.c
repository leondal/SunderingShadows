#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create(){
   set_monsters(({MON"piratecrew"}),({2}));
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Short hallway");
   set_short("Short hallway");
   set_long("%^BOLD%^Short hallway%^RESET%^\n"
"Leading in from the main deck is this hallway, beneath the foremost section of the ship.  Despite it being "
"entirely closed in, it's still partially %^YELLOW%^lit %^RESET%^by the few small, round windows along the "
"walls.  The roof, walls and floor are made of the same %^ORANGE%^timber%^RESET%^, a little weathered by "
"time, but have been recently %^WHITE%^%^BOLD%^polished%^RESET%^.  Off to the south opens a room full of "
"assorted beds and hammocks, while the hallway continues eastward.\n");
   set_smell("default","You smell fresh ocean air, lightly spiced with hints of tobacco.");
   set_listen("default","The waves of the ocean lap at the boat's sides.");
   set_items(([
     ({"deck","boards","wooden boards","roof","walls"}):"Wooden boards form the entirety of the roof, floor "
"and walls.  They are a little weathered over time, but they've obviously been polished recently."
   ]));
   set_exits(([
     "east":COVE"boatb08",
     "south":COVE"boatb07",
     "maindeck":COVE"boatb04"
   ]));
}
