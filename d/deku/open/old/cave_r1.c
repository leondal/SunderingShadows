#include <std.h>

inherit "/d/deku/open/cave_r3i.c";

void create() {
    ::create();
    set_property("light",1);
    set_long(
@KAYLA
This is the lair of Vexia, the worst greenhag in the realm.  The cave is 
carved through some areas of solid rock, sediment, and tree roots.  The
walls and ceilings are held together by brick, wooden beams, and mud-
cement packing.  The floors are uneven and covered with soft-packed dirt
and bat droppings.
KAYLA
    );
    set_smell("default","The bat droppings give off a strong ammonia smell.");
    set_exits(([
       "out" : "/d/deku/open/cave_ent2",
       "north" : "/d/deku/open/rec"
    ] ));
}

void init() {
  ::init();
}

void reset() {
  ::reset();
  if(!present("bat"))             new("/d/deku/monster/bat")->move(TO);
  if(!present("bat 2"))           new("/d/deku/monster/bat")->move(TO);
  if(!present("bat 3"))           new("/d/deku/monster/bat")->move(TO);
  if(!present("bat 4"))           new("/d/deku/monster/bat")->move(TO);
  if(!present("bat 5"))           new("/d/deku/monster/bat")->move(TO);
  if(!present("bat 6") && !random(4))    new("/d/deku/monster/bat")->move(TO);
}
