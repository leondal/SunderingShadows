#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_short("Abyss Conference Room");
    set_long(
@KAYLA
This wide cavern serves as a conference room.  There is a door in the
wall to the left and a similar door straight ahead.  Cobwebs hang thickly
from the ceiling and support pillars of this room.  The dirt floor is moist
and hard packed.
KAYLA
    );
    set_listen("default","You hear scuffling sounds of something large east.");	
    set_smell("default","The air smells moldy and feels damp.");
    set_exits(([
       "west" : "/d/deku/dark/elf8",
       "east" : "/d/deku/dark/giants",
       "north" : "/d/deku/dark/human"
    ] ));
    set_items(([
    ] ));
    set_pre_exit_functions(({"north"}),({"go_north"}));
}

void reset() {
  ::reset();
  if(!random(2)) {
   if(!present("ogre")) {
     new("/d/deku/monster/ogre")->move(TO);
   }
   if(!present("deep")) {
     new("/d/deku/monster/deep")->move(TO);
   }
   if(!present("human_follower")){
     new("/d/deku/monster/human1")->move(TO);
   }
  }
}

int go_north() {
   if(present("human_follower")){
    write("%^MAGENTA%^The human says:%^RESET%^ The ambassador cannot be disturbed.");
    return 0;
  }
  return 1;
}
