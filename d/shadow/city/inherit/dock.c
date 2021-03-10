//Octothorpe (12/3/16)
//Shadow, Dock Inherit

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_travel(BACK_ALLEY);
   set_terrain(CITY);
   set_climate("temperate");
   set_name("Pier in the Shadow Docks");
   set_short("%^ORANGE%^Pier in the %^BOLD%^%^BLACK%^Shadow "+
   "%^RESET%^%^ORANGE%^Docks, Shadow%^RESET%^");
   set_long("%^ORANGE%^Pier in the %^BOLD%^%^BLACK%^Shadow "+
      "%^RESET%^%^ORANGE%^Docks, Shadow%^RESET%^\n "+
      "This pier is constructed of weathered %^ORANGE%^timbers "+
      "%^RESET%^that extends out over the waters of the "+
      "%^BOLD%^%^BLUE%^Sarcosta River%^RESET%^. The pier is "+
      "cluttered with barrels, crates, and coiled up rope, that "+
      "makes makes travelling in a straight line for more than a "+
      "couple yards impossible. A multitude of boats and ships are "+
      "found moored to the pier on either side. Vessels as small as "+
      "the keelboats that ply the %^BOLD%^%^BLUE%^Sarcosta%^RESET%^, "+
      "to the larger trading caravels that sail the %^BOLD%^%^BLUE%^"+
      "Saakrune Sea %^RESET%^and parts unknown, create a dense forest "+
      "of hulls and rigging all around you. To the southwest, the "+
      "ancient %^BOLD%^Puente Zincharo %^RESET%^looms over the docks "+
      "as it crosses over the river to the southern shore.");
   set_smell("default","You smell damp wood and muddy river water.");
   set_listen("default","You hear the soft lapping of water "+
      "against the pylons of the pier.");
   set_items(([
      ({"pier","timbers"}) : "The pier is constructed out stout timbers "+
        "sourced from the nearby Darkwood Forest.",
      ({"barrels","crates","rope"}) : "Various crates, barrels, and "+
         "other cargo are staged on the pier as they are being loaded "+
         "or offloaded from the ships.",
      ({"vessels","keelboats","caravels","boats","ships"}) : "Numerous "+
         "littoral and oceangoing vessels are moored up and down the pier.",
      ({"bridge","Puente Zincharo","puente zincharo"}) : "The ancient, "+
         "stout bridge looms over the docks. The Sarcosta lazily flows "+
         "under its trio of arches.",
      ({"river","Sarcosta River","sarcosta river","Sarcosta","sarcosta"}) : "The "+
          "broad river flows slowly under the Puente Zincharo, and past "+
          "the docks into Shadow Bay.",
   ]));   
}
