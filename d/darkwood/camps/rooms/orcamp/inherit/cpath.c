#include <std.h>
#include "../../../elfisland1.h"

inherit ROOM;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",1);
   set("short", "A dirt road through the forest");
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
   set("long",
      "%^RESET%^%^GREEN%^The road here is small and narrow. It is a footworn path created by"+
      " often use. The plant life of the forest crosses over the path here and there, but its obvious which way"+
      " the path heads through the forest. The trees and thick plant life mark the edges of each side of the trail,"+
      " making it hard for several people to walk side by side. As you look up into the trees you see a few ripped"+
      " branches and signs of abuse of the forest. However, only a few of the scars on the trees look recent."
   );
   set_smell("default", "%^RESET%^%^ORANGE%^The forest has its own scent.%^RESET%^");
   set_listen("default", "%^RESET%^%^CYAN%^The forest is silent, except for the occasional forest creature.");
}
