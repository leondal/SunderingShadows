#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(HEAVY_FOREST);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",0);
    set_short("Kobold Forest");
    set_long(
@KAYLA
You are along the forest edge.  Toward the east rise the great
oak trees of Kobold Forest.  Toward the west rise the great
mountains. Fog covers the ground, and you cannot see the top of
the mountain.  Through the thick fog you see a cave opening.
KAYLA
    );
      set_listen("default","Peculiar, the forest is deadly quiet.");
    set_exits(([
       "enter" : "/d/deku/new/cave1",
       "east" : "/d/deku/new/new10"
    ] ));
    set_items(([
       "forest" : ".",
       "trees" : "."
    ] ));
}

void init() {
  ::init();
  do_random_encounters(({"/d/deku/monster/goblin"}),90,6);
}

void reset() {
  ::reset();
  if(!present("guard")) {
    new("/d/deku/monster/goblin1")->move(this_object());
    new("/d/deku/monster/goblin1")->move(this_object());
  }
}
