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
You are deep within the mysterious Kobold Forest.  All
around you fog blankets the forest in a thick dark gray.
The path twists in a boggled fashion toward the south.
The main path runs east and west.
KAYLA
    );
     set_listen("default","Peculiar, the forest is deadly quiet.");
    set_exits(([
       "west" : "/d/deku/new/new19",
       "south" : "/d/deku/new/new21",
       "north" : "/d/deku/new/new30",
       "east" : "/d/deku/new/new8"
    ] ));
    set_items(([
    ] ));
}

void init() {
  ::init();
  do_random_encounters(({"/d/deku/monster/kobold"}),90,5);
}

void reset() {
  ::reset();
  if(!present("gnome")) {
    new("/d/deku/monster/gnome2")->move(this_object());
  }
  if(!present("kobold")) {
    new("/d/deku/monster/kobold")->move(this_object());
    new("/d/deku/monster/kobold")->move(this_object());
  }
}
