#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "Bottom of the interior walls of the Rose Keep."
  );
  set_long(
  "Bottom of the interior walls of the Rose Keep\n"
  "  The outer walls of the keep rise sharply to the north while to the south the inner keeps walls fade upwards into the grey sky."
  "  The walls fade to the east and west into the gloom almost making you feel as if you are trapped in a corridor far underground."
  "\n"
  );
  set_smell("default",
  "The faint smell of blood hangs in the air."
  );
  set_listen("default",
  "Footsteps echo on stones far above you."
  );
  set_items(([
  ]));
  set_exits(([
  "east":KEEP"k16.c",
  "west":KEEP"k18.c",
  ]));
}
