//cleaned up by Circe with new desc by Cythera 8/31/05
#include <std.h>
#include "../tormdefs.h"

inherit VAULT;

void create(){
  ::create();
  set_terrain(WOOD_BUILDING);
  set_travel(DIRT_ROAD);
  set_property("indoors",1);
  set_property("light",2);
  set_door("door",TCITY+"c23","north","masterkey");
  set_smell("default","The salt air mixes with the smells of the herbs and other components.");
  set_listen("default","You can still hear the far away waves of the Dagger Sea.");
  set_name("Alvero's Mystics Haven");
  set_short("Alvero's Mystics Haven");
  set_long(
     "Alvero's Mystics Haven.\n"+
     "%^MAGENTA%^Alvero keeps a clean shop even if it seems to "+
     "have been constructed with only her diminutive frame in "+
     "mind.  Most people feel like giants walking around the "+
     "shop with all its low-lying %^ORANGE%^desks%^MAGENTA%^ "+
     "and %^ORANGE%^shelves%^MAGENTA%^ with their %^GREEN%^herbs"+
     "%^MAGENTA%^ and %^CYAN%^knick-knacks%^MAGENTA%^.  There "+
     "are numerous %^ORANGE%^shelves%^MAGENTA%^, %^BLUE%^drawers"+
     "%^MAGENTA%^, %^BOLD%^%^CYAN%^bottles%^RESET%^%^MAGENTA%^, "+
     "and even %^RESET%^sacks%^MAGENTA%^ and %^ORANGE%^crates"+
     "%^MAGENTA%^ full of components placed around the room.  "+
     "The floor is covered in a %^BOLD%^%^RED%^dark red carpet "+
     "%^RESET%^%^MAGENTA%^with a %^BOLD%^%^CYAN%^pale blue border"+
     "%^RESET%^%^MAGENTA%^, and you can see stains on it in a few "+
     "places. Otherwise the shop seems to be well-kept.%^RESET%^\n");
   set_items(([
   ({"carpet","red carpet"}) : "%^RED%^The dark red carpet bears stains from various components in places, but for the most part is kept clean. It is worn rather thin and is obviously not the first priority of the shop keeper.",
   ({"shelves","drawers","bottles","sacks","crates"}) : "All over the room there are various components stacked in whatever containers can hold them. Some are carefully labeled in neat jars, while others are practically spilling out of the sacks or bottles they've been placed in. A bit more organization wouldn't hurt."
   ]));
  set_exits(([
  "north":TCITY+"c23"
  ]));
}
void reset(){
  ::reset();
  if(!present("alvero",TO)){
  new(MON+"compkeeper")->move(TO);
  }
}
