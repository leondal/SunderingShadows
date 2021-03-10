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
walls.  There are doors to either side of the hallway.
KAYLA
    );
    set_exits(([
       "south" : "/d/deku/fortress/hallN1",
       "north" : "/d/deku/fortress/stair1",
       "west" : "/d/deku/fortress/room2",
       "east" : "/d/deku/fortress/fire_pit"
    ] ));
    set_pre_exit_functions(({"north"}),({"go_north"}));
    set_smell("default","A faintly nauseating smell of death and decay hangs in the air.");
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("guard")) {
    new("/d/deku/fortress/monster/guard")->move(TO);
    new("/d/deku/fortress/monster/guard")->move(TO);
    new("/d/deku/fortress/monster/guard")->move(TO);
  }
}

int go_north() {
  if(present("fortress guard")) {
    tell_room(ETP, "%^GREEN%^The Fortress guard block your way northward!");
    return 0;
  }
  return 1;
}
