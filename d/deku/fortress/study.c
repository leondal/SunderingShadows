#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("Study Room");
    set_long(
@KAYLA
%^YELLOW%^Study Room%^RESET%^
This room has kept its former splender.  The plush carpet on the
floor is undamaged and the chairs and couches are all richly
upholstered.  A small table sits in the center of the room.  A
tapestry covers the east wall and this is the only indication
that the fortress has recently changed hands.  Several large
candelabras provide steady light for the chamber.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/fortress/hallW1",
       "west" : "/d/deku/fortress/alter"
    ] ));
    set_items(([
       "tapestry" : "It displays a huge black dragon, jaws apart, spewing flame over a small village.",
       "table" : "A pair of crystal goblets and a crystal decanter sparkle from atop the table."
    ] ));
}

void reset() {
  ::reset();
  if(!present("banshee")) {
    new("/d/deku/fortress/monster/banshee")->move(TO);
  }
}
