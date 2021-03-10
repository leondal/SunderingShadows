#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_short("Cleric's sanctuary");
    set_long(
@KAYLA
The skeletal remains of many humans and humanoids are scattered 
throughout this cave.  Numerous pieces of rotting vestments and 
leather armor have fallen away from the bones.  On the opposite 
side of the cavern is a pile of rubble.
KAYLA
    );
     set_smell("default","You smell the stench of rotten flesh.");
     set_listen("default","You hear eerie echoes from the caverns.");
    set_exits(([
       "east" : "/d/deku/dark/room6"
    ] ));
    set_items(([
       "rubble" : "Rocks seem to have fallen from the ceiling and covered "
           "some of the skeletons.  They don't look worth digging out though."
    ] ));
}

void reset() {
  ::reset();
  if(!present("cleric")) {
    new("/d/deku/monster/cleric")->move(TO);
  }
}
