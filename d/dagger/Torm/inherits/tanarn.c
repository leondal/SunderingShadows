#include <std.h>
#include "../tormdefs.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_property("light",2);
  set_short("Road in north Torm");
  set_long(
  "Road in north Torm.\n"
  "  North Tanar road follows the city walls of Torm east and west here."+
  "  A smaller wall that surrounds Torm's park blocks your sight south,"+
  " although you can just see the tall spires of Torm's city hall over it."
  );
  set("night long",
  "%^BLUE%^"
  "A light fog blankets the streets here, obscuring much of the road."+
  "  Torm's city wall is to the north, visible above the fog.  The"+
  " houses of the citizens of Torm are all closed and quiet at night."+
  "  Another smaller wall surrounding the city's park lies to the south."
  );
  set_smell("default","You smell salt in the air from the Dagger Sea.");
  set_listen("default","Far away the breakers pound on the docks.");
  set_items(([
  ({"wall","small wall"}) : "There is a smaller wall that runs to the south"+
  " here, blocking your view of the city park.",
  ]));
}
