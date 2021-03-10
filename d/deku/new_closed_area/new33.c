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
You have stumbled upon a dead end. The path seems to just stop.
The marshland seems to endlessly extend to the north and west. 
Light endlessly tries to penetrate the dark leaves of the forest.
The marshland looks too difficult to move through.
KAYLA
    );
    set_exits(([
       "east" : "/d/deku/new/new32"
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
