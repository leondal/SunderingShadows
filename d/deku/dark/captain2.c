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
tapestries display grisly hunting scenes to either side of the stairway.
The wide stairway to the north leads down to something unknown.
KAYLA
    );
    set_exits(([
       "down" : "/d/deku/dark/stair3",
       "west" : "/d/deku/dark/elf3"
    ] ));
    set_pre_exit_functions(({"down"}),({"go_down"}));
    set_items(([
       "stair" :"The stairs are wide but all you see downward is darkness."
    ] ));
}

void reset() {
  ::reset();
  if(!random(3))
  if(!present("elf")) {
    new("/d/deku/monster/captain")->move(TO);
    if(!random(3))
      new("/d/deku/monster/captain")->move(TO);
      new("/d/deku/monster/elite")->move(TO);
  }
}

int go_down() {
  if(present("captain")) {
    write("The drow captain forbids your journey downward.");
    return 0;
  }
  return 1;
}
