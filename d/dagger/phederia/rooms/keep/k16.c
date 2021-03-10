#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "At the bottom of the Dismal walls of the Rose Keep."
  );
  set_long(
  "At the bottom of the Dismal walls of the Rose Keep.\n"
  "  The walls of the rose keep rise above you here blocking even the grey light that permeates the whole area."
  "  A dim building is faintly visible to the east and the walls fade away to grey to the west and the steep walls of the inner keep rise up to the south."
  "\n"
  );
  set_smell("default",
  "The smell of blood lays faint in the air."
  );
  set_listen("default",
  "Echoing footsteps ring from contacts on stone somewhere above you."
  );
  set_items(([
  "building":"A dim stone building set into the base of the corner of the outer wall.  Not much can be seen of it.",
  "walls":"The walls seem to fill you with dread and imposing menace towering over you.",
  ({"keep","inner keep"}):"All you can see are the walls fading into the greyness above you.",
  ]));
  set_exits(([
  "east":KEEP"k15.c",
  "west":KEEP"k17.c",
  ]));
}
