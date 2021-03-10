#include <std.h>
#include "../tormdefs.h"
inherit ROOM;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
  set_short("Street in northwest Torm");
  set_property("light",2);
  set_long(
  "Street in northwest Torm.\n"
    "  Torm stretches out to the east and south from here."
    "  A walled compound's gates are southeast from you here and roads lead south and east, as well as a set of stairs leading up to a watchtower on the outer walls."
   "  Houses line the streets and people wander about going about their daily business around you."
  );
  set("night long","%^BLUE%^"
  "A light fog has settled over the city this night."
  "  Stairs lead up to a watchtower that is free from the fog, which"+
  " stays low to the ground.  The gates to a walled compound are"+
  " southeast of here.  The streets lie quite and you hear only a"+
  " distant shuffling of feet.  All the shutters of the houses that"+
  " line the street are closed and everyone seems to be tucked into bed."
  );
  set_exits(([
  "up":TCITY+"c2a",
  "east":TCITY+"c3",
  "south":TCITY+"c11",
  "southeast":TCITY+"c97",
  ]));
  set_smell("default","You smell the salt sea air of the Dagger Sea.");
  set_listen("default","Far away the breakers hit the docks.");
  set_items(([
  (({"compound","walled compound"})):"  Tall walls block all but the top of a spire of a grand mansion behind them.",
  "houses":"The houses of the citizens of Torm for the most part are simple but well made structures.  All their doors are closed and locked.",
  ]));
}
