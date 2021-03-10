#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Large Cell");
    set_long(
@KAYLA
This chamber holds the skeletal remains of a number of humanoids.  In
the northeast corner lies a body of a recently deceased prisoner. 
The corpse is dressed in tattered leather armor.
KAYLA
    );
     set_smell("default","The smell of rotten flesh fills your lungs.");
    set_exits(([
       "south" : "/d/deku/fortress/torture"
    ] ));
    set_items(([
       "corpse" : "It looks like a dead corpse of a human prisoner."
    ] ));
}

void reset() {
  ::reset();
  if(!present("skeleton") && !random(2)) {
    new("/d/deku/monster/skeleton")->move(TO);
    new("/d/deku/monster/skeleton")->move(TO);
    new("/d/deku/monster/skeleton")->move(TO);
  }
}
