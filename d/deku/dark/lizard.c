#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(RUBBLE);
    set_short("Lizard Playroom");
    set_long(
@KAYLA
This room is very dry.  The floor is littered with the rotting vestiges
of barrels that once held water and provisions.  The metal hoops about
the barrels have rusted away.
KAYLA
    );
     set_smell("default","The air is very stale.");
    set_exits(([
       "north" : "/d/deku/dark/tomb",
       "south" : "/d/deku/dark/room1"
    ] ));
    set_pre_exit_functions(({"north"}),({"go_north"}));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("lizard")) {
    new("/d/deku/monster/lizard")->move(TO);
    new("/d/deku/monster/lizard")->move(TO);
  }
}

int go_north() {
  if(present("lizard")) {
    write("The lizard blocks you journey northward.");
    return 0;
  }
  return 1;
}
