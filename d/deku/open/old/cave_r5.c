#include <std.h>

inherit "/d/deku/open/cave_r3i.c";

void create() {
   ::create();
   set_long(  ::query_long()+"To the north, a door is broken off the hinges "
      "and stands ajar.");
   set_listen("default","You hear roars and scuffling to the north.");
   set_exits(([
       "north" : "/d/deku/open/ogre",
      "south" : "/d/deku/open/lair",
       "east" : "/d/deku/open/cave_r2"
    ] ));
}
