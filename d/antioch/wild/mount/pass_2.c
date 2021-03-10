//  Created by Ignatius, for ShadowGate
//  Coded 04 March, 1995
//  The Trail to Antioch

#include <std.h>
#include "/d/antioch/areadefs.h"

inherit ROOM;

void create() {
  ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_climate("mountain");
  set_property("light", 1);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_listen("default",
    "The wind chills your bones."
  );
  set_smell("default",
    "The scent of fear comes from the north."
  );
  set("short",
      "In the Charu Mountains"
     );
  set("long",
    "%^CYAN%^In the Charu Mountains
%^CYAN%^You are walking through a narrow pass in the northern reaches of the Charu Mountains. Here, the mountains tower overhead, blocking out much of the light. Little grows in this area, just a few sprigs of crabgrass and a whole lot of dirt."
      );
  set_exits( ([
    "southeast": MOUNT+"pass_1",
    "west": MOUNT+"pass_3"
    ]) );
  set_items( ([
    "mountains":
      "The mountains extend as far as the eye can see."
    ]) );
}
/*
void init() {
  ::init();
  do_random_encounters( ({
    MON+"dwarf",MON+"dking"
    }), 40, 4);
}
*/
