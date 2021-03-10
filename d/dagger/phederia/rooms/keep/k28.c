#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "Courtyard of the Rose Keep."
  );
  set_long(
  "Courtyard of the Rose Keep.\n"
  "  You stand in the gloom cast by the walls and the everpresent low clouds."
  "  A small stone building stands north of you while the courtyard continues east and west."
  "\n"
  );
  set_smell("default",
  "Traces of blood linger in the air."
  );
  set_listen("default",
  "You can hear footsteps as someone patrols the walls."
  );
  set_items(([
  ]));
  set_exits(([
  "north":KEEP"k21.c",
  "east":KEEP"k29.c",
  "south":KEEP"k35.c",
  ]));
}
