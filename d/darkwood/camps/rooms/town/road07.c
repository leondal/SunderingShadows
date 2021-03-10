#include <std.h>
#include "../../elfisland1.h";
inherit "std/pier";

void create() {
   ::create();
   set_property("indoors", 0);
   set_property("light", 2);
   set("short", "%^BOLD%^%^YELLOW%^Village pond%^RESET%^");
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
   set("long",
      "%^RESET%^%^GREEN%^This is a well defined path that leads from the center of town to"+
      " the large pond where many come to relax and enjoy nature."+
      " There are several solid oak benches placed sporadically around the pond for seating."+
      " You see bridges that connect platforms cross over the pond high up in the trees."
   );
   set_smell("default", "%^RESET%^%^ORANGE%^You can smell the fresh scent of the forest.%^RESET%^");
   set_listen("default", "%^RESET%^%^CYAN%^You can hear the peaceful sounds of the village life.%^RESET%^");
   set_items( ([
      "pond":"This pond is fairly large, but could not be considered a lake.",
      "bridges":"There are many trees linked to one another up above your head.",
      "benches":"Solid oak benches have been placed here for anyone to rest and enjoy the view." 
   ]) );
   set_max_fishing(4);
   set_chance(17);
   set_max_catch(6);
   set_fish( ([ "Issaquah Trout": 3, "Big Kahuna": 10]) );
   set_exits( ([
      "east" : TOWN+"center",
   ]) );
}

void reset() {
   ::reset();
   if(!present("statue"))
new("/d/darkwood/camps/obj/statue.c")->move(TO);
}

