#include <std.h>
#include "/d/dagger/Torm/tormdefs.h"
inherit BAR;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
   remove_property("indoors");
   set_short("Patio of the Seahorse restaurant");
  set_long(
   "Patio of the Seahorse restaurant.\n"
  "  Sitting out here you have a grand view of the harbor of Torm, and of the boardwalks that stretch out onto the Dagger Sea."
  "  The sea itself dominates the horizon to the north, east, and south and the image of nothing but the majesty of the waves leaves you breathless at times."
   "  A few white birds hover nearby but they seem well mannered almost as if trained to hover about and add atmosphere to the patio."
   "  There are a few larger tables setup out here, all of which have their own umbrella-like structures on top of them to give some shade to the diners.  There is a nice breeze that always seems to be blowing, keeping the place cool."
  );
  set("night long",
  "Sitting out here you have a view of the fog that settles over the"+
  " city of Torm at night.  Out here on the Dagger Sea it almost looks"+
  " as if a wall surrounds the city even from the sea, protecting it"+
  " from pirates or other predators of the night."
  );
   set_items(([
   "tables" : "The tables are similar to those inside, the tops are done in pieces of tile that come together to show a picture. One depicts the image of a pod of dolphins swimming through the ocean, while another shows a crystalline castle deep under the sea. Each table has a pole emerging from the center, with a large canopy expanding out from it that can provide shade to the diners.",
   "floor" : "The floor is kept carefully swept and free from dirt. There is no carpet here since it would be quickly ruined this close to the ocean, but the boards are sturdy and have been given a darker stain and coat of varnish to help preserve them.",
   ]));
   set_smell("default","Sea spray drifts on the breeze.");
   set_listen("default","You hear the relaxing pounding of the waves.");
  set_exits(([
  "west":TCITY+"c94",
  ]));
}

/* Stealing the other barkeep for the Fist and making this one load in the 
other room and do double duty  *Styx* 3/9/02
void reset(){
  ::reset();
  if(!present("waitstaff",TO)){
  new(MON+"barkeep6")->move(TO);
  }
}
*/