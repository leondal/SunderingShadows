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
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_listen(
    "default",
    "You hear small people working in the area."
    );
  set_smell(
    "default",
    "The scent of fear fills this mountain range."
    );
  set("short",
      "In the Charu Mountains"
     );
  set("long",
      " \n"
    "%^CYAN%^In the Charu Mountains
The peaks of the Charu Mountains jut toward the sky all around you, blocking out much of the suns light and all of its warmth. Cold air whistles down this path, the smell of death and fear strong in your nose.\n"
      );
  set("night long",
      "  The peaks of the Charu Mountains are outlined by the moon.  A "
      "wolf howls in the distance.\n"
     );
  set_exits( ([
    "south":  MOUNT + "pass_5",
   "north" : "/d/antioch/ruins/rooms/gates",
   "northwest" : "/d/antioch/antioch2/rooms/trail1",
    ]) );
  set_items( ([
    "mountains":
      "The mountains extend as far as the eye can see."
    ]) );
}

void init() {
  ::init();
  do_random_encounters( ({ MON+"wolf"}), 50, 6);
}
