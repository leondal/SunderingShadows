//  Created by Grolim, for ShadowGate
//  Coded 18 Jun, 1995
//  Forest around Antioch

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;
int is_virtual() { return 1; }

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set("short","A trail."
     );
  set("long","This is one of many trails that links different cities. "
             "You can follow it or you can explore the Dark forest. "
             "A tree blown down by the wind blocks the trail to the south. "
      " \n"
    );
  set_exits( ([
    "north": "/realms/grolim/virtual/antiforest/8,10.antiforest.c",
    "east": "/realms/grolim/virtual/antiforest/10,10.antiforest.c",
    "southwest": "/realms/grolim/virtual/antiforest/10,9.antiforest.c",
    ]) );
  set_search("river", "There is no river around here ....!"
  );
  set_smell("default","You smell fresh lumbered wood."
  );
  set_listen("default","You hear lumberjacks cutting a tree down."
  );
  set_items( (["trail" : "It's just lying there.", 
               "trees" : "Trees, which have been here for years.",
               "tree" : "Just a tree blown down by the wind.",
            ({ "lumberjacks", "lumberjack" }) : "The trees are blocking your vision.",
               "birds" : "All types and varieties, singing and flying around.",
               "flowers" : "It seems as if they had grown here forever.",
               "flower" : "A nice looking one.",
            ({ "forest", "east" }) : "A mystical forest of pure evil.",
    ]) );
}

void init() {
  ::init();
}
