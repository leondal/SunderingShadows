//  Created by Grolim, for ShadowGate
//  Coded 23 Feb, 1995
//  Forest around Antioch

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
   set_terrain(HEAVY_FOREST);
   set_travel(DIRT_ROAD);
   set_climate("mountain");
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set("short","A trail."
     );
  set("long","This is one of many trails that links different cities. "
             "You can follow it or you can explore the Dark forest. "
             "But the paths aren't always well marked, so here is some advice: "
             "If you're lost find some sort of river, follow it. "
             "It might lead you somewhere."
      " \n"
    );
  set_exits( ([
    "north": FOREST+"trail4",

    "south": FOREST+"trail2"
    ]) );
  set_search("river","There is no river around here ....!"
  );
  set_smell("default","You smell fresh flowers."
  );
  set_listen("default","The wind howls through the trees."
  );
  set_items( (["trail" : "It's just lying there.",
               "trees" : "Trees, which have been here for years.",
               "tree" : "Tree, which has been here for years.",
               "flowers" : "It seems as if they had grown here forever.",
               "flower" : "A nice looking one."
    ]) );
}

void init() {
  ::init();
}
