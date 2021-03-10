#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "Courtyard in the Rose Keep."
  );
  set_long(
  "Courtyard in the Rose Keep.\n"
  "  The sky still hangs low and gloom fills the air like a fog."
  "  Through the haze you can see a short hedge blocking passage to the east while the courtyard extends in all other directions fading away."
  "\n"
  );
  set_smell("default",
  "Blood lingers in the air."
  );
  set_listen("default",
  "The hedges stir as you near them."
  );
  set_items(([
  ({"hedges","short hedges","hedge"}):"This is the same sort of hedge that you had to fight your way through to get here.  The thorns on these ones seem just as anxious to draw your blood if you get to close.",
  ]));
  set_exits(([
  "north":KEEP"k22.c",
  "south":KEEP"k36.c",
  "west":KEEP"k28.c",
  ]));
}
