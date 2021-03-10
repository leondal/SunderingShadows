#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Keep Blacktongue");
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_long(
@KAYLA
%^YELLOW%^Keep Blacktongue%^RESET%^
You are at the northwest corner of the keep.  The cobblestone path
continues south and east.  Somewhat to the east is the armor shop
and to the northwest is another guard tower.
KAYLA
    );
    set_exits(([
       "northwest" : "/d/deku/keep/towerNW1",
       "east" : "/d/deku/keep/keepW7",
       "south" : "/d/deku/keep/keepW5"
    ] ));
    set_pre_exit_functions(({"northwest"}),({"go_northwest"}));
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

int go_northwest() {
  if(present("kguard")) {
    write("The guard forbids your entrance into the tower!");
    write("%^MAGENTA%^The guard says:%^RESET%^ The tower is forbidden from the likes of you, "+TP->query_race()+"!");
    return 0;
  }
  return 1;
}
