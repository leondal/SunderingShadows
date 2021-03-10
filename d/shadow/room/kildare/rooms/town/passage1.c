//passage1.c
#include <std.h>
#include "../../kildare.h"

inherit VAULT;

void create()
{
   ::create();
   set_indoors(1);
   set_property("light",1);
   set_terrain(STONE_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("Passageway");
   set_short("A secret passageway");
   set_long(
      "The narrow passageway has a floor and ceiling of stone, but "+
      "walls formed of tongue and groove wooden planks.  A long narrow "+
      "rug lines the floor and muffles sound here.  The passageway comes "+
      "to an end here, with a door in the northern wall and the hallway "+
      "continuing to the east."

   );
   set_items(([
      (({"floor","rug","woven rug"})) : "The stone floor of the hallway has been "+
         "worn smooth by use.  A long woolen rug in a muted shade of %^ORANGE%^brown "+
         "%^RESET%^lines the entire hallway, masking sound from this room.",
      (({"wall","walls","wooden walls"})) : "The wooden walls are well-made and "+
         "have darkened over the years."
      ]));
   set_smell("default","The hallway smells slightly musty.");
   set_listen("default","Sound in the hallway is muffled by the thick rug.");

   set_exits(([
      "east" : TROOMS"leader2",
      "north" : TROOMS"passage2"
      ]));
   set_door("small door",TROOMS"passage2","north","caldon room_key");
   set_door_description("small door","The small door is well-made and "+
      "very sturdy.  The brass doorknob has a small keyhole.");
   set_locked("small door",1,"lock");
   lock_difficulty("small door",20,"lock");
}
