#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create(){
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Short hallway");
   set_short("Short hallway");
   set_long("%^BOLD%^Short hallway%^RESET%^\n"
"The hallway ends here, beneath the foremost section of the ship.  Despite it being entirely closed in, it's "
"still partially %^YELLOW%^lit %^RESET%^by the few small, round windows along the walls.  The roof, walls "
"and floor are made of the same %^ORANGE%^timber%^RESET%^, a little weathered by time, but have been "
"recently %^WHITE%^%^BOLD%^polished%^RESET%^.  Off to the south and east open two moderately-sized rooms, "
"while the hallway itself continues west, back toward the ship's main deck.\n");
   set_smell("default","You smell fresh ocean air, lightly spiced with hints of tobacco.");
   set_listen("default","The waves of the ocean lap at the boat's sides.");
   set_items(([
     ({"deck","boards","wooden boards","roof","walls"}):"Wooden boards form the entirety of the roof, floor "
"and walls.  They are a little weathered over time, but they've obviously been polished recently."
   ]));
   set_exits(([
     "east":COVE"boatb10",
     "south":COVE"boatb09",
     "west":COVE"boatb06"
   ]));
   set_pre_exit_functions(({"east",}),({"GoThroughDoor",}));
}

int GoThroughDoor(){
   if(!present("ships mate")) return 1;
   tell_object(TP,"There's no way past the ship's mate, who is standing in guard of that doorway.");
   return 0;
}

void reset() {
   if(!has_mobs()) {
     if(mons) mons = ([]);
     switch(random(3)) {
       case 0:
       set_monsters(({MON"piratecrew",MON"mate2"}),({2,1}));
       break;
       case 1:
       set_monsters(({MON"piratecrew2",MON"mate2"}),({2,1}));
       break;
       case 2:
       set_monsters(({MON"piratecrew3",MON"mate2"}),({2,1}));
       break;
     }
   }
   ::reset();
}
