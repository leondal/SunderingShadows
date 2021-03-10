//     /d/dragon/tower1/room1.c

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
This room is very bright, with light coming from the four crystal globes,
one in each corner of the room. A large oval table sits in the center of
the room, and a large bookcase dominates the norther wall.
GRAYHAWK
     );
    set_exits(([
       "east" : "/d/dragon/tower2/tower"
    ] ));
    set_items(([
       "bookcase" : "The bookcase is empty, only dust resides on the shelves.",
       "globe" : "A 1' diameter silver sphere enchanted with magic.  It is\n"+
                 "fixed in place and impossible to remove."
    ] ));
}
