#include <std.h>
#include "../tormdefs.h"
inherit ROOM;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
  set_short("North lighthouse on the walls of Torm");
  set_property("light",2);
  set_property("indoors",1);
  set_long(
  "North lighthouse on the walls of Torm.\n"
  "  A great beacon fire is stationed here at the northern edge of the walls of Torm."
  "  You look down from the walls onto the Dagger Sea far from the shore."
  "  The beacon looks as though it's well maintained, but looking out"+
  " to sea you can tell that there are many rocky outcroppings that"+
  " would probably be hard to avoid at night.  Far to the south you can"+
  " see another beacon like this one on the walls at the far side of the harbor."
  );
  set("night long",
  "A bright beacon lights up the night here, sending its beam out into"+
  " the ocean to help guide any ships that may wish to risk docking"+
  " at night.  A fog has settled over the lower parts of the city, and"+
  " it extends a little ways into the sea.  It is probably a natural"+
  " phenomenon given the positioning of the city, which seems to"+
  " encourage the fog to stay within.  At one point when there were"+
  " more pirates or things to fear, it was probably a great defense."
  );
  set_smell("default","You smell salt in the air from the Dagger Sea.");
  set_listen("default","Far away the breakers pound on the docks.");
  set_items(([
  "beacon" : "There is a large beacon here than can be lit at night"+
  " to help guide ships who wish to risk the rocky perils to dock here.",
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
  "northwest":TCITY+"c20",
  ]));
}
