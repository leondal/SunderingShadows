#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(BUILT_TUNNEL);
    set_travel(DIRT_ROAD);
    set_short("Deadlord's Vault");
    set_long(
@KAYLA
This cavern is lighted by four braziers that stand in each corner of
the room.  In the middle of the room, just to the north of the center, a
pedestal stands four feet from the floor.  Atop this stand is a large
black book in a shimmering red aura.  In the west, and the east are
semicircular alcoves.
KAYLA
    );
    set_exits(([
       "south" : "/d/deku/dark/hall7"
    ] ));
    set_items(([
   "alcoves" : "Large chests sit prominently within each.",
       "book" : "This is the evil Deadlord's spellbook.  One page looks important.",
   "pedestal" : "This is a very elaborate pedestal.",
       "page" : " The page reads:\n"+
                "\n"+
                "       It goes where it wills\n"+
                "         and seeks many spaces,\n"+
                "       And when it is gone\n"+
                "         it leaves few traces.\n"
    ] ));
}

void reset() {
  ::reset();
  if(!present("deadlord") && !random(2)) {
    new("/d/deku/monster/lord")->move(TO);
  }
}
