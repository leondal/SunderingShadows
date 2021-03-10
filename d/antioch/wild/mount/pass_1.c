#include <std.h>
#include "/d/antioch/areadefs.h"

inherit ROOM;

void create() {
  ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_climate("mountain");
  set_property("light", 3);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_listen("default", "A moaning wind slides down the mountains to your ear." );
  set_smell("default", "The scent of fear fills this mountain range." );
  set("short",
      "In the Charu Mountains"
     );
  set("long",
      "%^CYAN%^In the Charu Mountains
%^CYAN%^The peaks of the Charu Mountains are outlined by the sky. A wolf howls in thedistance. Cold air whistles down this path, the smell of death and fear strong in yournose."
      );
  set_exits( ([
    "northwest": MOUNT+"pass_2",
    "south":  "/d/shadow/room/pass/pass30",
    "north": MOUNT+"pass_10"
    ]) );
  set_items( ([
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
