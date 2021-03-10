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
is the rusting remnant of a great longsword.
KAYLA
    );
     set_smell("default","You smell the stench of mortal flesh.");
    set_exits(([
       "east" : "/d/deku/dark/mobat",
       "west" : "/d/deku/dark/elf5"
    ] ));
    set_items(([
    ] ));
    set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));
}

void reset() {
  ::reset();
  if(!present("elf") && !random(3)) {
    new("/d/deku/monster/elite")->move(TO);
    new("/d/deku/monster/elite")->move(TO);
    if(!random(3))
    new("/d/deku/monster/elf")->move(TO);
  }
}

int GoThroughDoor() {
  if(present("darkelf")) {
    tell_room(ETP, "The guards blocks the entrance to the east!!");
    return 0;
  }
  return 1;
}
