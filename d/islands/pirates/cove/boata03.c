#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create(){
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Forecastle");
   set_short("Forecastle");
   set_long("%^BOLD%^Forecastle%^RESET%^\n"
"This is the forward deck of the pirate boat, made up of %^ORANGE%^wooden boards %^RESET%^that are probably "
"long overdue for a polish.  The tiller is positioned here, and further forward is the prow of the boat, "
"carved in the image of a rather buxom female.  A %^ORANGE%^low rail %^RESET%^runs around the length of the "
"deck.  From this higher vantage point, you have a clear view of the ship's main deck just below you, as "
"well as a vast expanse of the %^BLUE%^%^BOLD%^ocean %^RESET%^for miles in any direction.\n");
   set_smell("default","You smell fresh ocean air minced with the smell of charred wood.");
   set_listen("default","You hear the boards of the ship creak in an unsettling way.");
   set_items(([
     ({"deck","boards","wooden boards"}):"The wooden boards beneath your feet form the forward deck of this "
"ship.  They look rather old, and are in need of a good polish.",
     "rail":"A low rail runs around the edge of the deck, though it's probably a bit too low to stop anyone "
"going overboard in a storm.",
     "tiller":"The tiller is set within the centre of this deck, set with grips at regular intervals.",
     "prow":"The ship's prow is set with a carving of a rather buxom female figure."
   ]));
   set_exits(([
     "maindeck":COVE"boata02"
   ]));
}

void reset() {
   if(!has_mobs()) {
     if(mons) mons = ([]);
     switch(random(3)) {
       case 0..1:
       set_monsters(({MON"firstmate",MON"piratecrew",MON"piratecrew3"}),({1,1,1}));
       break;
       case 2:
       set_monsters(({MON"firstmate",MON"piratecrew2",MON"piratecrew3"}),({1,1,1}));
       break;
     }
   }
   ::reset();
}
