// A Cove Landing on the Wadi
// al-Emir, Verhedin Province 
// Brings players into the forest
// virtual area
// Thorn@ShadowGate
// 13 June 2000
// cove1.dock.c

#include <std.h>

inherit "/d/verhedin/virtual/wadi/landing.c";

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() {
  set_indoors(0);
  ::create();
  set_light(2);
  set_short("A Sandy Riverbank");
  set_long(
@THORN
%^BOLD%^A Sandy Riverbank%^RESET%^
  You are now in a small clearing in a forest.  A path
seems to lead off deeper into the forest.  To your west is
a sandy river bank that seperates a wide river from the
forest.  Here, you could easily land a boat or launch one
into the river. 
THORN
);
  set_exits(([
        "east" : "/d/verhedin/virtual/x,y.forest"
  ]));
  set_smell("default","You smell the flora and fauna of the river ahead.");
  set_listen("default","You hear the water lapping up against the dock.");
}
