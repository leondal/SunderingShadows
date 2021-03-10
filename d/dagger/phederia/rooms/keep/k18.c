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
  "A faint building is seen to the south through the gloom of the courtyard and the walls continue both east and west from you."
  "\n"
  );
  set_smell("default",
  "The smell of blood lays faint in the air."
  );
  set_listen("default",
  "Echoing footsteps ring from contacts on stone somewhere above you."
  );
  set_items(([
  "building":"This short wide wood buildings door hangs open and the sound of water comes from in it.",
  "walls":"The walls seem to fill you with dread and imposing menace towering over you.",
  ({"keep","inner keep"}):"All you can see are the walls fading into the greyness above you.",
  ]));
  set_exits(([
  "east":KEEP"k17",
  "west":KEEP"k19.c",
  "south":KEEP"k24.c",
  ]));
}
