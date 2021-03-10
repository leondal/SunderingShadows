#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(NAT_CAVE);
   set_travel(DIRT_ROAD);
    set_property("light",0);
    set_property("indoors",1);
    set_short("Kobold Caverns");
    set_long(
@KAYLA
You are moving deeper into the mountains side.  All around you
the stone is naturally carved.  This cave seems small because
of the bones of humanoids are completely covering the ground.
KAYLA
    );
      set_listen("default","Peculiar, the cavern is deadly quiet.");
      set_smell("default","The stench of rot, is overwhelming in this cave.");
    set_exits(([
       "east" : "/d/deku/new/cave6"
    ] ));
    set_items(([
       "bones":"Some of the humanoids still have greasy meat attached to it.",
       "walls" : "The cavern walls are natural formed."
    ] ));
}


void reset() {
  ::reset();
  if(!present("lizard")) {
    new("/d/deku/monster/lizard")->move(this_object());
  }
}
