//Octothorpe (12/19/16)
//Shadow, Dock Inherit

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_travel(FOOT_PATH);
   set_terrain(GARDEN);
   set_climate("temperate");
   set_name("A serene garden in Shadow");
   set_short("%^GREEN%^A serene garden in %^BOLD%^%^BLACK%^Shadow%^RESET%^");
   set_long("%^GREEN%^A serene garden in %^BOLD%^%^BLACK%^Shadow%^RESET%^\n "+
      "This.\n\n");
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