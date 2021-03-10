//added bandits in inherit to hold down people camping out inside to kill the 
//giant and for a little more variety.  Styx 7/21/01

#include <std.h>

inherit "/d/deku/open/stair1";

void create() {
    ::create();
    set_travel(STAIRWAY);
    set_property("light",1);
    set_long(
@KAYLA
As you enter the tower, reek of decay rushes into your lungs making it
hard to breath.  Only a small amount of light enters from the front
door which hangs in the wind.  The stairway is nearly complete darkness.
The steps creak as you walk upward into the darkness.
There is some light coming from up above.
KAYLA
    );
    set_exits(([
       "up" : "/d/deku/open/top_tower",
       "down" : "/d/deku/open/stair2"
    ] ));
    set_items(([
    ] ));
}

void init() {
  ::init();
}

void reset() {
  ::reset();
}
