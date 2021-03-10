// Dock Entrance near Verhedin docks
// on the Wadi al-Emir, Verhedin City 
// Thorn@ShadowGate
// 12 June 2000
// 11,1.wadi.c

#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
    set_indoors(0);
    ::create();
    set_light(2);
    set_short("%^BOLD%^You are on the Wadi al-Emir near the Verhedin River Dock.%^RESET%^");
    set_property("no teleport",1);
    set_long(
@THORN
%^BOLD%^You are on the Wadi al-Emir near the Verhedin River Dock.%^RESET%^
Looking west, you can see the substantial number of docks that serve the
river boats that trade between Verhedin and the cities to the south.
To the east, you see the river running its course out of the city to
the south.
THORN
        );
        set_exits(([
                "dock":"/d/verhedin/virtual/wadi/verhedin.dock.c",
                "east":"/d/verhedin/virtual/11,2.wadi"
                ]));

        set_smell("default","You can detect all sorts of scents coming from the city.");
        set_listen("default","You can hear the waves lapping at the nearby docks.");
}

