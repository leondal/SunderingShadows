#include <std.h>

inherit "/d/deku/inherits/vexia-lair.c";

void create() {
    ::create();
    set_property("light",1);
    set_short("Guard chamber");
    set_long(
@KAYLA
Torches line the walls of this room.  Leading from the cellar through 
this 20 ft. square chamber into the arched northern doorway is a trail 
of sticky sour mead.  Against the east wall, between the eastern and 
northern openings is a 10 ft. tall chair.
KAYLA
    );
    set_exits(([
       "east" : "/d/deku/open/lab",
       "south" : "/d/deku/open/cellar",
       "north" : "/d/deku/open/exec",
       "northwest" : "/d/deku/open/cave_r8"
    ] ));
    set_pre_exit_functions(({"northwest"}),({"GoThroughDoor"}));
    set_items(([
       "chair" : "This 10 ft. tall chair looks suited for a very large creature.",
       ({"mead", "trail"}) : "The trail of mead appears to have leaked out of "
          "something and dribbled in a trail along the floor."
    ] ));
}

void reset() {
  ::reset();
  if(!present("ogre guard")) {
    new("/d/deku/monster/ogre3")->move(TO);
    new("/d/deku/monster/ogre3")->move(TO);
  }
}

int GoThroughDoor() {
   if(present("dekuogre")) {
    tell_room(ETP, "%^MAGENTA%^The ogre booms%^RESET%^: No go!!");
    return 0;
  }
  return 1;
}
