// Fortress Quay on the Wadi
// al-Emir, Verhedin City 
// Thorn@ShadowGate
// 14 June 2000
// quay.dock.c

#include <std.h>

inherit "/d/verhedin/virtual/wadi/dock.c";

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() {
  set_indoors(0);
  ::create();
  set_light(2);
  set_short("Fortress Quay, Verhedin");
  set_long(
@THORN
%^BOLD%^Fortress Quay, Verhedin%^RESET%^
  You have stepped on to Fortress Quay, the military river dock
for Verhedin's New Fortress.  Although the dock is significantly 
smaller than Verhedin River Dock, it is just as busy as troops
and supplies come in and out via riverboat.
  To the east, you see the dock gate into New Fortress.
THORN
);
  set_exits(([
        "east" : "/d/verhedin/fort/dockgate"
  ]));
  set_smell("default","Various scents assault your nose from the many cargoes.");
  set_listen("default","You hear constant loading and unloading of boats around you.");
}
