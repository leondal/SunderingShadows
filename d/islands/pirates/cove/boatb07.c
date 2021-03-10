#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create(){
   set_monsters(({MON"piratecrew",MON"piratecrew2",MON"piratecrew3"}),({2,2,1}));
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Sleeping quarters");
   set_short("Sleeping quarters");
   set_long("%^BOLD%^Sleeping quarters%^RESET%^\n"
"This room is fairly large, considering the size of the ship.  Despite it being entirely closed in, it's "
"still partially %^YELLOW%^lit %^RESET%^by several small, round windows that have been placed within the far "
"wall.  The roof, walls and floor are made of the same %^ORANGE%^timber%^RESET%^, a little weathered by "
"time, but have been recently %^WHITE%^%^BOLD%^polished%^RESET%^.  Around the rooms are an assortment of "
"beds, bunks and hammocks, probably where most of the pirates rest.  The single doorway leads back to the "
"north, into a short hallway.\n");
   set_smell("default","You smell fresh ocean air, lightly spiced with hints of tobacco.");
   set_listen("default","The waves of the ocean lap at the boat's sides.");
   set_items(([
     ({"deck","boards","wooden boards","roof","walls"}):"Wooden boards form the entirety of the roof, floor "
"and walls.  They are a little weathered over time, but they've obviously been polished recently.",
     ({"beds","bunks","hammocks"}):"An assortment of beds, bunks and hammocks are scattered around the room, "
"most in quite a state of disarray.  This is probably where most of the pirates sleep."
   ]));
   set_exits(([
     "north":COVE"boatb06"
   ]));
}
