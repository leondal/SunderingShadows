//  Created by Ignatius, for ShadowGate
//  Coded 06 March, 1995
//  Along the Antioch Trail

#include <std.h>
#include "/d/antioch/areadefs.h"

inherit ROOM;

void create() {
  ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_climate("arctic");
  set_property("light", 1);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_listen("default", "A moaning wind slides down the mountains to your ear." );
  set_smell("default", "The scent of fear fills this mountain range." );
  set("short",
      "In the Charu Mountains"
     );
  set("long",
      " \n"
    "  You are deep in the Charu Mountains, far from civilization.  Here, "
    "a lone road travels through the mountains toward the village of "
   "Antioch.  Perhaps this is a road, or perhaps this is merely a side "
    "route that leads only to doom.\n"
    "  The wind continues to blow from the north here, almost as if Mother "
    "Nature herself was trying to keep you away from this place.\n"
      );
  set("night long",
      "  The Charu range fills the night sky.  Only a few lonely, dim "
      "stars shine down on your pathetic little being.\n"
     );
  set_exits( ([
    "north": MOUNT + "trail1",
    "south": MOUNT + "pass_10"
    ]) );
  set_items( ([
    "mountains":
      "The mountains extend as far as the eye can see."
    ]) );
}
