#include <std.h>

inherit "/d/deku/open/cave_r3i.c";

void create() {
    ::create();
    set_long(
@KAYLA
You are getting deeper into Vexia's lair, the worst greenhag in the realm.
The cave is carved through some areas of solid rock, sediment, and tree 
roots.  The walls and ceilings are held together by brick, wooden beams, 
and mud-cement packing.  The floors are uneven and covered with soft-
packed dirt.  There is another door hanging broken and only partially on 
its hinges to the west and stairs going east that lead into darkness.
KAYLA
    );
    set_exits(([
       "down" : "/d/deku/open/cellar",
       "west" : "/d/deku/open/ogre_den",
       "south" : "/d/deku/open/kitchen"
    ] ));
    set_items(([
       "door" : "The door is made of split oaken logs bound together with iron "
         "strips.  It has a huge iron latch without a lock and is now useless."
         "  You suspect the ogres don't care for doors much."
    ] ));
}

void init() {
  ::init();
  add_action("west","west");
  do_random_encounters(({"/d/deku/monster/ogre1"}),60,2);
}

int west() {
  write("%^ORANGE%^The door rattles noisily as you bump it moving past.");
  tell_room(ETP, "%^ORANGE%^The door rattles noisily as "+TPQCN+" bumps into "
    "it going westward.", TP);
  TP->move_player("/d/deku/open/ogre_den");
  return 1;
}
