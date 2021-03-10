#include <std.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Keep Blacktongue");
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_long(
@KAYLA
%^YELLOW%^Keep Blacktongue%^RESET%^
You are at the southeast corner of the keep.  The cobblestone path
continues north and west.  Somewhat to the west is the entrance gate
leading outside to the dark forest.  There seem to be some buildings
to the north.  To the southeast is one of the guard towers.
KAYLA
    );
    set_exits(([
       "southeast" : "/d/deku/keep/towerSE1",
       "west" : "/d/deku/keep/keepE1",
       "north" : "/d/deku/keep/keepE3"
    ] ));
    set_pre_exit_functions(({"southeast"}),({"go_southeast"}));
    set_smell("default","Dust and ale permeate the halls of this Keep.");
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("kguard")) {
    new("/d/deku/keep/monster/keep_guard")->move(TO);
    new("/d/deku/keep/monster/keep_guard")->move(TO);
  }
}

go_southeast() {
  if(present("kguard")) {
    write("The guard forbids your entrance into the tower.");
    write("%^MAGENTA%^The guard says:%^RESET%^ You cannot enter the tower, "+TP->query_race()+"!");
    return 0;
  }
  return 1;
}
