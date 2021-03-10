#include <std.h>
#include "../../elfisland1.h"
inherit "/std/room";

void create() {
   ::create();
   set_property("indoors", 0);
   set_property("light", 2);
   set_property("night light",1);
   set("short", "%^BOLD%^%^YELLOW%^Gathering place%^RESET%^");
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
   set("long",
      "%^RESET%^%^GREEN%^This clearing in the forest leads off from the path stemming from the"+
      " village's central square. Wooden benches have been set out around the clearing, making this"+
      " an ideal place to sit and relax. The trees arch overhead with branches, which provides shade"+
      " for the people that gather here.%^RESET%^"
   );
   set_smell("default", "%^RESET%^%^ORANGE%^You can smell the fresh scent of the forest.%^RESET%^");
   set_listen("default", "%^RESET%^%^CYAN%^You can hear the peaceful sounds of the village life.%^RESET%^");
   set_items( ([ 
      "clearing": "This clearing has several benches in it.", 
      "benches":"The benches have all been crafted from wood and have elegant"+
      " and detailed carvings covering the armrests and seatbacks.", 
      "trees":"The trees outline the edges of this clearing." 
   ]) );
   set_exits( ([
      "north" : TOWN+"road06",
      "south" : TOWN+"road14",
   ]) );
}
