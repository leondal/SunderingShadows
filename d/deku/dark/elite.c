#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_short("Darkelf elite guards");
    set_long(
@KAYLA
Many skeletal forms lie near the east entrance to this cavern. A number
of rotting weapons and sundered pieces of decrepit armor are scattered
amongst the grisly debris.  Near the west wall are the large skeletal
remains of a man hunched against the rock wall.  Beneath these bones
is the rusting remnant of a great shield.
KAYLA
    );
     set_smell("default","You smell the stench of mortal flesh.");
    set_exits(([
       "north" : "/d/deku/dark/queen",
       "east" : "/d/deku/dark/room2"
    ] ));
    set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("elf")) {
    new("/d/deku/monster/elite")->move(TO);
    new("/d/deku/monster/elite")->move(TO);
    if(!random(4))
      new("/d/deku/monster/captain")->move(TO);
    if(!random(3))
      new("/d/deku/monster/elite")->move(TO);
  }
}

int GoThroughDoor() {
  if(present("darkelf")){
    tell_room(environment(this_player()), "The guards forbid "+this_player()->query_cap_name()+" from entering the chamber of their queen!");
    return 0;
  }
  return 1;
}
