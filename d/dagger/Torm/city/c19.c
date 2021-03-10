#include <std.h>
#include "../tormdefs.h"
inherit ROOM;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
  set_property("light",2);
  set_long(
  "On the walls leading to the north lighthouse.\n"
  "  The walls of Torm here begin to extend out into the Dagger Sea."
  "  North you can see a rocky outcropping and a path that leads out to a temple at the waters edge."
  "  The Dagger Sea fills the horizon to the east and you can see the coast line extend back east a bit into the city."
  "  The docks and boardwalks can clearly be seen here with their ships and people doing business."
  "  Here the walls are thicker than the other places with a walkway atop them southeast further onto the Dagger Sea."
  );
  set("night long",
  "On the walls leading to the north lighthouse.\n"
  "A light fog has settled over most of the city at night, but it"+
  " doesn't reach up to the walls and from here you can see over the"+
  " rest of the city.  The walls of Torm begin to extend out into the"+
  " Dagger Sea here.  North you can see a rocky outcropping and there"+
  " seems to be a path that leads out to a temple at the waters edge."+
  "  The Dagger Sea fills the horizon to the east and you can see the"+
  " coast line extend back east a bit into the city.  The docks and"+
  " boardwalks can clearly be seen from here, but there is little"+
  " activity at night."
  );
  set_short("North lighthouse walls");
  set_smell("default","You smell salt in the air from the Dagger Sea.");
  set_listen("default","Far away the breakers pound on the docks.");
  set_items(([
  "harbor" : "The east side of Torm is open to the Dagger Sea, with many boardwalks and docks from the city going out into it.",
  "fog" : "A light fog has settled over the city of Torm, but it stays"+
  " close to the ground and you can see the tops of all the buildings"+
  " from here.",
  ({"boardwalks","docks"}):"  Long wooden docks stretch out on the harbor providing space for the ships that sail these waters access to the city.  A few of them are big enough to have shops and stalls set out on them.",
  ({"sea","dagger sea","Dagger Sea"}):"  The dagger sea sparkles as it comes right into the city of Torm on its east side in a great harbor with boardwalks and docks stretching out onto it.",
 ({"city","Torm","torm","buildings","building"}):"The city of Torm is very ornate, with many of the buildings having tall spires reaching from their roofs.  You can see three walled mansions in the city, one in each corner besides the one open to the sea where the harbor is. A great open marketplace lies in the center of Torm with a walled park, with another great building in it to the marketplaces north.", 
  ({"walls","city walls"}):"The walls here are much thicker as they extend over the sea itself.  There is a walkway here that leads to a lighthouse at this corner of the harbor.",
  ]));
  set_exits(([
  "down":TCITY+"c10",
  "southeast":TCITY+"c20",
  ]));
}
