//m2

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_short("An old alchemy lab");
     set_properties((["indoors":1,"light":1]));
   set_long(
@OLI
   %^MAGENTA%^An old alchemy lab%^RESET%^
%^BOLD%^%^WHITE%^This lab is a small area. Obviously the monks have tried
to store the knowledge of chemicals and such here. You see
%^RESET%^%^ORANGE%^%^BOLD%^%^WHITE%^ lining the walls with the bottles, vials, and beakers.
%^RED%^Dust%^BOLD%^%^WHITE%^ covers everything, and it's obvious that this is not a well
used area.%^RESET%^
OLI
   );
   set_items(([
      "shelves":"These are dusty and bent. They hold many cob webbed vials and flasks.",
      "vials":"These vials contain many many colors and textures of things.",
      "beakers":"Some of these beakers contain the results of mixtures some are empty.",
   ]));
   set_exits(([
      "north":MONASTERY+"m34",
      "east":MONASTERY+"m33",
      "south":MONASTERY+"m37",
      "west":MONASTERY+"m38",
   ]));
   set_smell("default","Must and dust make you cough.");
   set_listen("default","Silence, this must be a truly forgotten room.");
}

void reset(){
   ::reset();
   if(!present("beaker")){
      new(OBJ+"beaker")->move(TO);
   }
}
