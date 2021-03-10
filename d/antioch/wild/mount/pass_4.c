//  Created by Ignatius, for ShadowGate
//  Coded 05 March, 1995
//  Along the Antioch Trail

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
  set_listen(
    "default",
    "Ancient trees far above you groan from the onslaught of the wind."
    );
  set_smell(
    "default",
    "You catch the faint scent of cooking meats."
    );
  set("short",
      "In the Charu Mountains"
     );
  set("long",
    "%^CYAN%^In the Charu Mountains
You are deep in the Charu Mountains, far from home and further from safety. Here, you spy rocks that seem to have recently fallen from a ledge above. It seems that here you are not even safe from Mother Nature.\nLooking north, you note a large keep at the peak of the highest mountain in the range. Of course, you're high enough up that even this extra height looks insignificant.\n"
      );
  set_exits( ([
    "northwest": MOUNT+"pass_5",
    "east": MOUNT + "pass_3"
    ]) );
  set_items( ([
    ({"rock", "rocks", "pile", "pile of rocks"}):
      "The rocks seem to block a path to the west.  Based on the size of "
      "these rocks, you have no hope of getting them moved.",
    "mountains":
      "The mountains extend as far as the eye can see."
    ]) );
}
/*
void init() {
  ::init();
  do_random_encounters( ({ MON+"wolf"}), 50, 6);
}
*/
