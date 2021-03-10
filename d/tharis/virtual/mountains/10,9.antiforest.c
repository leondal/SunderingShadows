//  Created by Grolim, for ShadowGate
//  Coded 18 Jun, 1995
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
  set("short","Beside the city wall."
     );
  set("long","As you left the trail you have a brief feeling being lost. "
             "The look of the city wall makes a strong impression on "
             "you, but you cann't reach it due to the moat. "
      " \n"
    );
  set_exits( ([
    "northeast": "/realms/grolim/virtual/antiforest/9,10.antiforest.c",
    "southeast": "/realms/grolim/virtual/antiforest/11,10.antiforest.c",
    ]) );
  set_search("river", "There is no river around here ....!"
  );
  set_smell("default","You smell fresh lumbered wood."
  );
  set_listen("default","You hear lumberjacks cutting a tree down."
  );
  set_items( (["trail" : "You see  a trail to the northeast and the southeast.", 
               "trees" : "Trees, which have been here for years.",
               "tree" : "Just a tree blown down by the wind.",
            ({ "lumberjacks", "lumberjack" }) : "The trees are blocking your vision.",
               "birds" : "All types and varieties, singing and flying around.",
               "flowers" : "It seems as if they had grown here forever.",
               "flower" : "A nice looking one.",
               "forest" : "A mystical forest of pure evil.",
               "east" : "A blown down tree is blocking your sight.",
               "moat" : "A deep, stinking one around Antioch.",
    ]) );
}

void init() {
  ::init();
}
