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
  You are moving deeper into the mountain's side.  All around you
the stone is magically carved.  This cavern is larger than the 
others.  Humanoid bones surround a large chair that sits in the
middle of the cave.  There are a couple of lit torchs along the walls.
KAYLA
    );
      set_listen("default","Peculiar, the cavern is deadly quiet.");
    set_exits(([
       "south" : "/d/deku/new/cave11"
    ] ));
    set_items(([
       "walls" : "The cavern walls are magically formed."
    ] ));
}


void reset() {
  ::reset();
  if(!present("king")) {
    new("/d/deku/monster/hobgob_k")->move(this_object());
    new("/d/deku/monster/hobgob")->move(this_object());
    new("/d/deku/monster/hobgob")->move(this_object());
    new("/d/deku/monster/hobgob")->move(this_object());
  }
}

