#include <std.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",0);
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_short("Keep Blacktongue");
    set_long(
@KAYLA
%^YELLOW%^Keep Blacktongue%^RESET%^
You are at the northeast corner of the keep.  The cobblestone path
continues south and west.  Somewhat to the west is the smithy shop
and to the northeast is another guard tower.
KAYLA
    );
    set_exits(([
       "northeast" : "/d/deku/keep/towerNE1",
       "west" : "/d/deku/keep/keepE7",
       "south" : "/d/deku/keep/keepE5"
    ] ));
    set_pre_exit_functions(({"northeast"}),({"go_northeast"}));
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

int go_northeast() {
  if(present("kguard")) {
    write("The guard forbids your entrance into the tower!");
    write("%^MAGENTA%^The guard says:%^RESET%^ The tower is forbidden from the likes of you, "+TP->query_race()+"!");
    return 0;
  }
  return 1;
}
