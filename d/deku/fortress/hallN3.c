#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("Shadowlord fortress");
    set_long(
@KAYLA
%^YELLOW%^Northern Hallway%^RESET%^
This hallway is furnished with great care, creating an atmosphere 
of comfort and luxury.  A plush purple carpet covers the floor,
and many tapestries of bright red and golden colors decorate the
walls.  Stairs lead down and to either side of the hallway,
there are doors.
KAYLA
    );
    set_exits(([
       "south" : "/d/deku/fortress/hallN4",
       "down" : "/d/deku/fortress/stair1",
       "east" : "/d/deku/fortress/room3",
       "west" : "/d/deku/fortress/room4"
    ] ));
    set_pre_exit_functions(({"west"}),({"go_west"}));
    set_pre_exit_functions(({"east"}),({"go_east"}));
    set_smell("default","A faintly nauseating smell of death and decay hangs in the air.");
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("guard")) {
    new("/d/deku/fortress/monster/guard")->move(TO);
    new("/d/deku/fortress/monster/guard")->move(TO);
  }
}

int go_west() {
  if(present("guard")) {
    tell_room(environment(this_player()), "%^GREEN%^The Fortress guard block your way!\n");
    return 0;
  }
  return 1;
}

int go_east() {
  if(present("guard")) {
    tell_room(environment(this_player()), "%^GREEN%^The Fortress guard blocks you way!");
    return 0;
  }
  return 1;
}
