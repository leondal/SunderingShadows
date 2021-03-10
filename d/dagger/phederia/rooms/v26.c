#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_short(
  "Open pasture."
  );
  set_long(
  "Open pasture.\n"
  "  This open pasture looks stangly sickly."
  "  The grass looks withered and dead even though before that it must of been very rich grazing for the animals that roamed here."
  "  The fences have been knocked down and the animals once here have started to wander in search of better feed."
  "\n"
  );
  set_smell("default",
  "You smell the far way smells of farm animals."
  );
  set_listen("default",
  "The animals cower away from you as if terrified of something."
  );
  set_items(([
  "grass":"Withered and dying you cant imagine any animal staying healthy eatin this sick looking grass.",
  "fences":"Once well done boards suppored by sturdy posts kept the animals where they should be.  Now they're free to wander as the fence has fallen to disrepair.",
  ]));
  set_exits(([
  "north":ROOMS"v24.c",
  "west":ROOMS"v25.c",
  "south":ROOMS"v27.c",
  ]));
}
