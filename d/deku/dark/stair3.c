#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(STAIRWAY);
    set_short("Stairway into darkness");
    set_long(
@KAYLA
These stairs lead deeper into the Underdark.  Evil spirits lurk 
throughout the cavern.  This evil penetrates your mortal soul.
Images of misery and pain appear before you as you continue
downward.
KAYLA
    );
    set_exits(([
       "down" : "/d/deku/dark/stair4",
       "up" : "/d/deku/dark/captain2"
    ] ));
    set_items(([
    ] ));
}
