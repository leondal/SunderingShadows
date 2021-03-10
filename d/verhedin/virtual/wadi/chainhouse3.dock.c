// A Landing just below a Chain House
// on the Wadi al-Emir, Verhedin City
// Allows person to climb into the chain
// slit to sneak into the walls without
// clearance.
// Thorn@ShadowGate
// 14 June 2000
// chainhouse3.dock.c

#include <std.h>

inherit "/d/verhedin/virtual/wadi/landing.c";

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() {
  set_indoors(0);
  ::create();
  set_light(2);
  set_short("Below the Southwest Chain House, Verhedin");
  set_long(
@THORN
%^BOLD%^Below the Southwest Chain House, Verhedin%^RESET%^
  You are on a patch of ground on the east bank of the river
facing a very tall structure that is connected to the city
walls.  This structure is solid stone except for the arrow
slits cut high into the wall and a larger opening farther
down from which the river chain emerges.
  Looking around, you see a section of the riverbank that
you could enter a boat to travel on the river.  
THORN
);
  set_exits(([
        "up" : "/d/verhedin/walls/swchain"
  ]));
  set_smell("default","You smell the flora and fauna of the river.");
  set_listen("default","You hear the water lapping up against the bank.");
}
