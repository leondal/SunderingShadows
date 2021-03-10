// Dock Entrance near Fortress Quay
// on the Wadi al-Emir, Verhedin City 
// Thorn@ShadowGate
// 12 June 2000
// 9,4.wadi.c

#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
    set_indoors(0);
    ::create();
    set_light(2);
    set_short("%^BOLD%^You are on the Wadi al-Emir near Fortress Quay, Verhedin.%^RESET%^");
    set_property("no teleport",1);
    set_long(
@THORN
%^BOLD%^You are on the Wadi al-Emir near Fortress Quay, Verhedin.%^RESET%^
You can get a good look from here at Verhedin's Fortress Quay to the east.
To the west, you see the river running its course into the city.
THORN
        );
        set_exits(([
                "dock":"/d/verhedin/virtual/wadi/quay.dock.c",
                "west":"/d/verhedin/virtual/9,3.wadi"
                ]));

        set_smell("default","You can detect all sorts of scents coming from the city.");
        set_listen("default","You can hear the waves lapping at the nearby quay.");
}

