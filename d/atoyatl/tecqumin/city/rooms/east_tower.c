#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit CVAULT;


void create() {
  ::create();
  ::create();
  set_property("indoors", 1);
  set_property("light", 0);
  set_short("A low rise stone tower");
  set_long("This low tower has no roof, but you can see the holes in the"
    +" walls that would once have held the beams supporting a circular"
    +" stair leading up to a raised battlement. There appears to be no way"
    +" up now.");
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_smell("default","The air is still and humid, carrying hints of the"
    +" perfumes of jungle plants");
  set_listen("default","The busy noises of the %^GREEN%^j%^BOLD%^"
    +"%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^"
    +"%^GREEN%^e%^RESET%^%^GREEN%^ are reduced to muffled whispers from outside.");
  set_items( ([     
       ({ "holes", "walls", "beams" }): "The squarish holes in the walls"
   +" would have once held strong wooden beams which supported a staircase"
   +" round the inside of the walls, and a battlement overhead. However,"
   +" there is nothing left of these structures now.",
   ]) );
  set_exits(([
     "north" : CITY_ROOM + "east_corridor2"
   ]));
  set_door("tower door", CITY_ROOM + "east_corridor2", "north", 0);
  set_door_description("tower door", "A simple, but functional"
    +" and very strong looking wooden door");
}


