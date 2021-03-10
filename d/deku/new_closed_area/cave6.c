#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(NAT_CAVE);
   set_travel(DIRT_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_short("Kobold Caverns");
    set_long(
@KAYLA
You are moving deeper into the mountain's side.  All around you
the stone is naturally carved.
KAYLA
    );
      set_listen("default","Peculiar, the cavern is deadly quiet.");
        set_smell("default","The stench of rot comes from the north and east.");
    set_exits(([
       "south" : "/d/deku/new/cave8",
       "west" : "/d/deku/new/cave7",
       "north" : "/d/deku/new/cave5"
    ] ));
    set_items(([
         "walls" : "The cavern walls are naturally formed."
    ] ));
}


void reset() {
  ::reset();
  if(!present("hobgoblin")) {
    new("/d/deku/monster/hobgob")->move(this_object());
  }
}
