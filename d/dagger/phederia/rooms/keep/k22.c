#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "Northwest corner of the Rose Keep courtyard."
  );
  set_long(
  "Northwest corner of the Rose Keep courtyard.\n"
  "  You stand at the northwest corner of the courtyard inside the walls of the Rose Keep, just to the north a building is set into the walls and the side of another small building is to the west."
  "  The courtyard fades off in the gloom to the south and east with little discernable."
  "\n"
  );
  set_smell("default",
  "The faint taint of blood hangs in the air."
  );
  set_listen("default",
  "You can hear the faint echos of armored footsteps on stone."
  );
  set_items(([
  ]));
  set_exits(([
  "north":KEEP"k20.c",
  "east":KEEP"k23.c",
  "south":KEEP"k29.c",
  ]));
}
