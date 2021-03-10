// Landing Entrance by the Chain Houses
// on the Wadi al-Emir, Verhedin City
// Thorn@ShadowGate
// 13 June 2000
// 11,3.wadi.c

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
of Verhedin City passing out of the city to the south.  The river
is wider here and it is a good distance to the west shore from here.
  You also see two fortified structures in the walls that are
connected by a massive chain hanging slackly below the water.  On the
east side, there appears to be a large metal ring and a patch of
ground that you could dock your boat and tie it up. 
THORN
    );
    set_exits(([
            "dock":"/d/verhedin/virtual/wadi/chainhouse2.dock.c",
            "north":"/d/verhedin/virtual/10,3.wadi",
            "south":"/d/verhedin/virtual/12,3.wadi",
            "west":"/d/verhedin/virtual/11,2.wadi"
             ]));

    set_smell("default","You can detect the scent of wet wood and earth.");
    set_listen("default","You can hear the waves lapping at the nearby shore.");
}

