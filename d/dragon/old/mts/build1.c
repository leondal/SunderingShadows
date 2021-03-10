//   /d/dragon/mts/build1.c

#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("Wooden Cabin");
    set_long("%^BLUE%^%^BOLD%^
Two gleaming brass lamps set high on the walls provide a harsh illumination.
A counter and desk are set against the left wall under the small window.
Silence fills the room, except for the soft heartbeat ticking of a mechanical
clock, which sits curiously undisturbed on the edge of the counter.  There
is a door set within the northern wall.
    ");
    set_exits(([
       "out" : "/d/dragon/mts/mts08",
       "north" : "/d/dragon/mts/build2"
    ] ));
    set_items(([                     
    ] ));
}
