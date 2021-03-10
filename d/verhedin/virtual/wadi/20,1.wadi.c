// Obscure Dock Entrance on
// the Wadi al-Emir, near Ninor
// Verhedin Province 
// Thorn@ShadowGate
// 12 June 2000
// 20,1.wadi.c

#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
    set_indoors(0);
    ::create();
    set_light(2);
    set_short("%^BOLD%^You are on the Wadi al-Emir.%^RESET%^");
    set_property("no teleport",1);
    set_long(
@THORN
%^BOLD%^You are on the Wadi al-Emir.%^RESET%^
To the west, you see a small inlet with a beach where you could
probably dock a small boat, if you were careful.
THORN
        );
        set_exits(([
                "west":"/d/verhedin/virtual/wadi/ninor.dock.c",
                "east":"/d/verhedin/virtual/20,2.wadi"
                ]));

        set_smell("default","You can smell the flora and fauna living near the shore.");
        set_listen("default","You can hear the river rolling up onto the sandy beach.");
}

