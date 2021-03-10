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
You have stumbled upon a dead end.  The path seems just to stop.
The forest seems to endlessly extend in all directions.  The
light endlessly tries to penetrate the dark leaves of the forest.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/new/new17"
    ] ));
    set_listen("default","Peculiar, the forest is deadly quiet.");
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("bear")) {
    new("/d/deku/monster/bear")->move(this_object());
  }
}
