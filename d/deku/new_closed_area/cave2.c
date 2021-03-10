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
the stone is naturally carved.
KAYLA
    );
      set_listen("default","Peculiar, the cavern is deadly quiet.");
    set_exits(([
       "west" : "/d/deku/new/cave3",
       "east" : "/d/deku/new/cave1"
    ] ));
    set_items(([
       "walls" : "The cavern walls are naturally formed."
    ] ));
}

