// Landing Entrance by the Chain Houses
// on the Wadi al-Emir, Verhedin City
// Thorn@ShadowGate
// 13 June 2000
// 8,2.wadi.c

#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
    set_indoors(0);
    ::create();
    set_light(2);
    set_short("%^BOLD%^You are on the Wadi al-Emir between the Chain Houses%^RESET%^");
    set_property("no teleport",1);
    set_long(
@THORN
%^BOLD%^You are on the Wadi al-Emir between the Chain Houses%^RESET%^
  The river winds lazily north to south past the walled river banks
of Verhedin City.
  You also see two fortified structures in the walls that are
connected by a massive chain hanging slackly below the water.  On the
east side, there appears to be a large metal ring and a patch of
ground that you could dock your boat and tie it up. 
THORN
    );
    set_exits(([
            "dock":"/d/verhedin/virtual/wadi/chainhouse1.dock.c",
            "north":"/d/verhedin/virtual/7,2.wadi",
            "south":"/d/verhedin/virtual/9,2.wadi"
             ]));

    set_smell("default","You can detect the scent of wet wood and earth.");
    set_listen("default","You can hear the waves lapping at the nearby shore.");
}

