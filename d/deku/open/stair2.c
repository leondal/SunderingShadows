#include <std.h>

inherit "/d/deku/open/stair1";

void create() {
    ::create();
    set_travel(STAIRWAY);
    set_long(
@KAYLA
As you enter the tower, reek of decay rushes into your lungs making it
hard to breath.  Only a small amount of light reaches this area, leaving 
the stairway in nearly complete darkness.  The steps creak as you walk 
upward into the darkness.
KAYLA
    );
    set_exits(([
       "up" : "/d/deku/open/stair3",
       "down" : "/d/deku/open/stair1"
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
