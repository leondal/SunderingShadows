//     /d/dragon/tower1/tower.c

#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("Ivory Tower");
     set_long(
@GRAYHAWK
A soft white glow pervades the inside of the Ivory tower.  By its unwavering
light, you can see most of the interior of this level.  There are doors 
within the east and west walls, and stairs leading up in the northwest
corner of the room.  In the center, suspended from the ceiling, is a silvery
globe that is apparently the source of the glow.
GRAYHAWK
     );
    set_exits(([
       "northwest" : "/d/dragon/tower/room3",
       "west" : "/d/dragon/tower1/room1",
       "south" : "/d/dragon/tower2/room2"
    ] ));
    set_items(([
       "globe" : "A 1' diameter silver sphere enchanted with magic.  It is\n"+
                 "fixed in place and impossible to remove."
    ] ));
}
