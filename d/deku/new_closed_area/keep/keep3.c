#include <std.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Keep Blacktongue");
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_long(
@KAYLA
%^YELLOW%^Keep Blacktongue%^RESET%^
This is the northern part of Keep Blacktongue.  To the south the
huge tower looks immense.  There is a shop to the southwest and
another southeast.  There is also a guard tower to the north.  The 
cobblestone path continues to the east and west.
KAYLA
    );
    set_exits(([
       "west" : "/d/deku/keep/keepW7",
       "north" : "/d/deku/keep/towerN1",
       "east" : "/d/deku/keep/keepE7"
    ] ));
    set_pre_exit_functions(({"north"}),({"go_north"}));
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

int go_north() {
  if(present("kguard")) {
    write("The guard forbids your entrance into the tower!");
    write("%^MAGENTA%^The guard says:%^RESET%^ The tower is forbidden to the likes of you, "+TP->query_race()+"!");
    return 0;
  }
  return 1;
}
