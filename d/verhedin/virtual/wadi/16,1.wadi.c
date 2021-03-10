// Dock Entrance near Pargin Ferry
// West on the Wadi al-Emir,
// Verhedin Province 
// Thorn@ShadowGate
// 12 June 2000
// 16,1.wadi.c

#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
    set_indoors(0);
    ::create();
    set_light(2);
    set_short("%^BOLD%^You are on the Wadi al-Emir near Pargin Ferry West.%^RESET%^");
    set_property("no teleport",1);
    set_long(
@THORN
%^BOLD%^You are on the Wadi al-Emir near Pargin Ferry West.%^RESET%^
To the west, you see can clearly see the Pargin Ferry dock on the 
western bank of the river.
THORN
        );
        set_exits(([
                "dock":"/d/verhedin/virtual/wadi/parginwest.dock.c",
                "east":"/d/verhedin/virtual/16,2.wadi"
                ]));

        set_smell("default","You can smell the scent of spices on the docks.");
        set_listen("default","You can hear the waves lapping at the nearby dock.");
}

