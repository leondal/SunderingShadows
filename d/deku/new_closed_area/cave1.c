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
You are in a small and dense cavern.  All around you the stone
is naturally carved.  Toward the south, a path leads deeper into the 
mountains.  Light comes through the opening to illumiate this
portion of the caves, but deeper within the cave is darkness.
KAYLA
    );
      set_listen("default","Peculiar, the cavern is deadly quiet.");
    set_exits(([
       "west" : "/d/deku/new/cave2",
         "out" : "/d/deku/new/new19"
    ] ));
    set_items(([
       "walls" : "The cavern walls are naturally formed."
    ] ));
}

