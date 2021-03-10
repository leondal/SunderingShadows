#include <std.h>
inherit ROOM;

void create(){
  ::create();
  set_terrain(WOOD_BUILDING);
  set_travel(DIRT_ROAD);
  set_property("light",2);
  set_property("indoors",1);
  set_short("Southern Inspiration");
  set_long("%^BOLD%^Southern Inspiration%^RESET%^\n"+
"%^RESET%^%^CYAN%^This shop is of broad floor space and no shelving.  Instead, %^ORANGE%^low tables %^CYAN%^have been "
"placed across its considerable space, and upon these lie its wares, sheaf upon stack of %^RESET%^parchment %^CYAN%^all "
"with a variety of text and notation marked upon their smooth surfaces.  Each is loosely bound to prevent stray %^BOLD%^"
"breezes %^RESET%^%^CYAN%^scattering them across the room, as the door and window-shutters stand open at the front of the "
"shop to allowing plenty of %^YELLOW%^light %^RESET%^%^CYAN%^to filter in from the street beyond.  Another door allows "
"access to the other half of this long building.");
  set_smell("default","The air is still and dry here.");
  set_listen("default","You can hear the bustle of the city street outside.");
  set_exits(([
    "east":"/d/darkwood/tabor/room/math8",
    "north":"/d/darkwood/tabor/room/instruments",
  ]));
}

void reset(){
   ::reset();
   if(!present("shihab")) new("/d/darkwood/tabor/mon/shihab")->move(TO);
}
