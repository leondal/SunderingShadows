// Dock Entrance near Nabat Ferry
// on the Wadi al-Emir, Verhedin
// Thorn@ShadowGate
// 12 June 2000
// 0,2.wadi.c

#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
    set_indoors(0);
    ::create();
    set_light(2);
    set_short("%^BOLD%^You are on the Wadi al-Emir%^RESET%^");
    set_property("no teleport",1);
    set_long(
@THORN
%^BOLD%^You are on the Wadi al-Emir%^RESET%^
You see the Nabat Ferry river dock to the north.
The river winds lazily south, into the heart of the Empire of Tsarven.
THORN
        );
        set_exits(([
                "dock":"/d/verhedin/virtual/wadi/nabat.dock.c",
                "south":"/d/verhedin/virtual/1,2.wadi"
                ]));

        set_smell("default","You can detect the scent of wet wood and earth.");
        set_listen("default","You can hear the waves lapping at the nearby dock.");
}

