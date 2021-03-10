// Dock Entrance near Pargin Ferry
// East on the Wadi al-Emir,
// Verhedin Province 
// Thorn@ShadowGate
// 12 June 2000
// 15,4.wadi.c

#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
    set_indoors(0);
    ::create();
    set_light(2);
    set_short("%^BOLD%^You are on the Wadi al-Emir near Pargin Ferry East.%^RESET%^");
    set_property("no teleport",1);
    set_long(
@THORN
%^BOLD%^You are on the Wadi al-Emir near Pargin Ferry East.%^RESET%^
To the east, you see can clearly see the Pargin Ferry dock on the 
eastern bank of the river.
THORN
        );
        set_exits(([
                "dock":"/d/verhedin/virtual/wadi/pargineast.dock.c",
                "west":"/d/verhedin/virtual/15,3.wadi"
                ]));

        set_smell("default","You can smell the scent of spices on the docks.");
        set_listen("default","You can hear the waves lapping at the nearby dock.");
}

