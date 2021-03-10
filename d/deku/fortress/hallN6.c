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
of comfort and luxury.  A plush purple carpet covers the floor
and many tapestries of bright red and golden colors decorate the
walls.  Before you is a pair of large oak doors.  Each door is 9
feet wide and 12 feet tall.  From the look of the hinges set into
the stone, each door must be 1 foot thick.  There are also stairs
here that lead down to the second level of the Fortress.
KAYLA
    );
    set_pre_exit_functions(({"north"}),({"go_north"}));
    set_exits(([
       "down" : "/d/deku/fortress/stair2",
       "north" : "/d/deku/fortress/hallN7"
    ] ));
    set_smell("default","A faintly nauseating smell of death and decay hangs in the air.");
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("beast")) {
    new("/d/deku/fortress/monster/beast")->move(TO);
    new("/d/deku/fortress/monster/beast")->move(TO);
  }
}

int go_north() {
   if(present("displacer beast")) {
    tell_room(environment(this_player()), "%^GREEN%^The displacer beast blocks the entrance to the north.%^RESET%^");
    return 0;
  }
  return 1;
}
