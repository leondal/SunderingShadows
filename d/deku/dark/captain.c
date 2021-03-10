#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_short("Darkelf Captain");
    set_long(
@KAYLA
This huge and darkened hall is paneled with mahogany.  Two huge
tapestries display hunting scenes to either side of the stairway.
The wide stairway to the north leads down to something unknown.
KAYLA
    );
    set_exits(([
         "north" : "/d/deku/dark/stair2", 
         "south" : "/d/deku/dark/elf2" 
    ] ));
    set_items(([
       "stair" : "The stairs lead down into the depths of hell."
    ] ));
    set_pre_exit_functions(({"north"}),({"go_north"}));
}

void reset() {
  ::reset();
  if(!random(3))
  if(!present("elf")) {
    new("/d/deku/monster/captain")->move(TO);
    if(!random(3))
      new("/d/deku/monster/captain")->move(TO);
  }
}

int go_north() {
  if(present("darkelf")) {
    write("The Drow blocks the northward passage!");
    return 0;
  }
  return 1;
}
