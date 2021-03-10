//  Created by Grolim, for ShadowGate
//  Coded 23 Feb, 1995
//  Forest around Antioch

#include <std.h>
#include </d/antioch/areadefs.h>
inherit ROOM;
int is_virtual() { return 1; }

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set("short","A forest entrance"
     );
  set("long","You are standing in front of the entrance to a dark forest. "
      "You cannot see further than a few meters of the path that is trailing "
      "into the forest. A second path leads north and a road leads to a city "
      "far to the west."
      " \n"
    );
  set_exits( ([
    "north": "/realms/grolim/virtual/antiforest/19,10.antiforest.c",
    "east": "/realms/grolim/virtual/antiforest/20,11.antiforest.c",
    "west": FOREST+"east_big_road2",
    "northeast": FOREST+"chapel_out",
    ]) );
  set_search("entrance","You find nothing but still ....."
  );
  set_smell("forest","You take a deep breath and walk further."
  );
  set_listen("default","You hear the sounds of birds who are content."
  );
  set_items( ([
    "entrance" : "The road blends into the wood, and disappears from view.",
    "path" : "It leads to the forest, but you cannot see further.",
    "road" : "The road seems worn, as if many adventurers have travelled upon it.",
    "forest" : "A mystical forest of pure evil.",
    "birds" : "All types and varieties, singing and flying around.",
    ]) );
}

void init() {
  ::init();
}

void reset() {
  ::reset();
  if(!present("sign"))
  new(FOREST+"forest_sign")->move(this_object());
}
