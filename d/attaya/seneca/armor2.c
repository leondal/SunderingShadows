#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
   set_short("Furnace");
   set_property("indoors",1);
   set_property("light",2);
   set_property("smithy", 1);
   set_long(
@DESC
This room is extremely hot. It houses the great smelting 
furnace that Angus and the metalsmiths here use to smelt 
the armors. There are diagrams on the wall and a few measuring 
threads hanging from pegs on the south wall. The smoke from 
the furnace rises through a large smokestack above it and a 
large stone slab serves as a bench upon which the armors are 
hammered. A barrel of rainwater beside the door is used to 
cool molten armors after they have been hammered.
DESC
   );
   set_smell("default","The air smells of smoke and metals.");
   set_exits(([
      "west" : "/d/attaya/seneca/armorshop",
   ]));
   set_items(([
      "furnace" : "The huge smelitng furnace is covered in black molten metals and looks quite used.  Raging fires burn inside and a metal rack is white hot within.",
      "threads" : "There are several marked cords hanging from pegs on the wall.  They are used to measure armors and fit them to their intended buyer.",
      "slab" : "This is a large slab of granite that is used to hammer armors out upon.",
      "bench" : "This is a large slab of granite that is used to hammer armors out upon.",
      "diagrams" : "Each diagram shows the design and materials needed to make a particular armor.",
      "barrel" : "It is a barrel of clear water.  Some metal shards and flash lie rusting at the bottom.",
   ]));
}

