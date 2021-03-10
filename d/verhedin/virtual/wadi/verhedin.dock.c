// Main City Dock on the Wadi
// al-Emir, Verhedin City 
// Thorn@ShadowGate
// 14 June 2000
// verhedin.dock.c

#include <std.h>

inherit "/d/verhedin/virtual/wadi/dock.c";

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() {
  set_indoors(0);
  ::create();
  set_light(2);
  set_short("City River Dock, Verhedin");
  set_long(
@THORN
%^BOLD%^City River Dock, Verhedin%^RESET%^
  This is the main river dock for the City of Verhedin.
Day and night, crews load and unload boats with cargoes
that bear final destinations that come from the farthest
corners of the Empire.
  To the west, you see the road leading to the Dock Gate
into Verhedin's Old City.  Also nearby are a number of 
warehouses, offices and taverns that are frequented by the
rivermen.
THORN
);
  set_exits(([
        "west" : "/d/verhedin/oldcity/dockgate"
  ]));
  set_smell("default","Various scents assault your nose from the exotic cargoes.");
  set_listen("default","You hear constant loading and unloading of boats around you.");
}
