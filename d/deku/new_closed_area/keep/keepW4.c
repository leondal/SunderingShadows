#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Keep Blacktongue");
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_long(
@KAYLA
%^YELLOW%^Keep Blacktongue%^RESET%^
This is the western part of the Keep.  Toward the east is some
kind of barracks with a sign:  Elite guards.  To the west is
another guard tower.  The cobblestone path continues to the 
north and south.
KAYLA
    );
    set_exits(([
       "west" : "/d/deku/keep/towerW1",
       "east" : "/d/deku/keep/barrack2",
       "south" : "/d/deku/keep/keepW3",
       "north" : "/d/deku/keep/keepW5"
    ] ));
    set_pre_exit_functions(({"west"}),({"go_west"}));
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

int go_west() {
  if(present("kguard")) {
    write("The guard forbids your entrance into the tower.");
    write("%^MAGENTA%^The guard says:%^RESET%^ You cannot enter the tower, "+TP->query_race()+"!");
    return 0;
  }
  return 1;
}
