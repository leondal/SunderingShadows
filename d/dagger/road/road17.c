// Modified to add access to Solaren's player house
// Thorn@ShadowGate
// 11 December 2000

#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create() {
  ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
  set_property("light", 2);
  set_short("The Dagger Sea coast road.");
  set_long(
@THORN
%^CYAN%^You are on the road through dagger that is moving inward from the
seacoast to the southwest.  To the south is the seaport of Torm, and to
the northeast is the town of Daggerdale.  To the east, you can make out
a narrow path that appears to lead into some hills in the direction of
the sea.
THORN
  );
    set_smell("default", "You can smell the salts of the sea on the cool breeze.");
    set_listen("default", "The sound of the waves on the cliffs below float up to your ears.");
    set_items(([
        "cliffs" : "You can see the ocean below the great granite cliffs",
        "sea" : "The great waves crash against the cliffs hundreds of feet below you.",
      ]));
    set_exits(([
        "east" : "/d/player_houses/solaren/solaren1",
        "northeast" : RPATH "road18",
        "southwest" : RPATH "road16"
      ]));
}
