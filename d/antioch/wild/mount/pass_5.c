//  Created by Ignatius, for ShadowGate
//  Coded 05 March, 1995
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
      " \n"
    "%^CYAN%^In the Charu Mountains
You are walking through a narrow pass in the northern reaches of the Charu Mountains. Here, the mountains tower overhead, blocking out much of the light. Little grows in this area, just a few sprigs of crabgrass and a whole lot of dirt.
While little grows here, you are certain that things live out here. Perhaps not even pleasant things...\n"
      );
  set_exits( ([
    "north":  MOUNT + "pass_6",
    "southeast": MOUNT + "pass_4"
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
    }), 60, 4);
}
*/
