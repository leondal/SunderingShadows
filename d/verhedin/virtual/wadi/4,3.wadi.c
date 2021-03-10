// Landing Entrance at a cove
// on the Wadi al-Emir, Verhedin
// Thorn@ShadowGate
// 13 June 2000
// 4,3.wadi.c

#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
    set_indoors(0);
    ::create();
    set_light(2);
    set_short("%^BOLD%^You are on the Wadi al-Emir in a small cove%^RESET%^");
    set_property("no teleport",1);
    set_long(
@THORN
%^BOLD%^You are on the Wadi al-Emir in a small cove%^RESET%^
  You are in a small cove by the shore.  To the east, you see that
the river bank is sandy.  You could probably dock your boat and
leave it on that beach.
THORN
    );
    set_exits(([
            "dock":"/d/verhedin/virtual/wadi/cove1.dock.c",
            "west":"/d/verhedin/virtual/4,2.wadi"
             ]));

    set_smell("default","You can detect the scent of wet wood and earth.");
    set_listen("default","You can hear the waves lapping at the nearby shore.");
}

