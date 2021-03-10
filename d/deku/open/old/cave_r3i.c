#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_name("Vexia's caves");
    set_short("Vexia's Lair");
    set_long(
@KAYLA
The cave here is carved through some areas of solid rock, sediment, and tree roots.  The walls and ceilings are held together by brick, wooden beams, and mud-cement packing.  The floors are uneven and covered with soft-packed dirt.  Torches are set in the wall every 10 ft. or so but some have run out of fuel.
KAYLA
    );
    set_smell("default","There is a damp, earthy smell.");
    set_listen("default","You hear scuttling, crawling noises from all around.");
    set_exits(([
       "north" : "/d/deku/open/cave_r4",
      "west" : "/d/deku/open/cave_r2",
       "east" : "/d/deku/open/well"
    ] ));
    set_items(([
       "floor":"It is hard to really call it a floor since it is mostly dirt.",
       "walls":"The walls are often cold, damp stone but otherwise simply dirt.",
       ({"torch", "torches"}):"They give off a sooty smoke but not a great deal "
         "of light.",
    ] ));
}

void reset() {
  ::reset();
  if(!present("ogre") && !present("bat")) {
    switch(random(7)) {
      case 0..1:  new("/d/deku/monster/ogre")->move(TO);          break;
      case 2:  if(!random(3))  
               new("/d/deku/monster/ogre1")->move(TO);
      case 3:  if(!present("large orc") && !random(5))   
               new("/d/deku/monster/orc")->move(TO);              break;
      case 4:  if(!random(3))
               new("/d/deku/monster/ogre3")->move(TO);
      case 5:  if(!present("bat 3") && !random(5))
               new("/d/deku/monster/bat")->move(TO);              break;
    }
  }
}
