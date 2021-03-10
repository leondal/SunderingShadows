#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_short("Vampire's antechamber");
    set_long(
@KAYLA
A maze of stalactites and stalagmites crowds this large cavern.  Here
and there, at odd intervals, lights seem to dance about the cave,
flashing in and out of the calcium formations.  
KAYLA
    );
set_smell("default","The air is particularly cold and clammy in this strange cavern.");
    set_exits(([
       "east" : "/d/deku/dark/vampire",
       "west" : "/d/deku/dark/elite2"
    ] ));
    set_items(([
    ] ));
}
void reset() {
  ::reset();
  if(!present("mobat")) {
    new("/d/deku/monster/mobat")->move(TO);
    new("/d/deku/monster/mobat")->move(TO);
    new("/d/deku/monster/mobat")->move(TO);
  new("/d/deku/monster/mobat")->move(TO);
  }
}
