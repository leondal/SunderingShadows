#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_short(
  "Hayfield."
  );
  set_long(
  "Hayfield.\n"
  "  This hayfield is overgrown and uncared for."
  "  It is well past harvest time and it doesnt look like anyone has put any interest in working with the field."
  "   The hay might once of been a perfect field but now the stalks hang grey and lifeless."
  "\n"
  );
  set_smell("default",
  "You smell the far way smells of farm animals."
  );
  set_listen("default",
  "The animals cower away from you as if terrified of something."
  );
  set_items(([
  "hay":"Withered, grey and dying.   It should of really been harvested a long time ago.",
  "fences":"Once well done boards suppored by sturdy posts kept the animals where they should be.  Now they're free to wander as the fence has fallen to disrepair.",
  ]));
  set_exits(([
  "north":ROOMS"v36.c",
  "west":ROOMS"v38.c",
  ]));
}
