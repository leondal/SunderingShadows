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
You are at the southwest corner of the Keep.  The cobblestone
path contines north and east.  Somewhat to the east is the
entrance gate, leading outside into the dark forest.  There 
seem to be some large buildings to the north and to the south
west is the opening to one of the guard towers.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/keep/keepW3",
       "east" : "/d/deku/keep/keepW1",
       "southwest" : "/d/deku/keep/towerSW1"
    ] ));
    set_pre_exit_functions(({"southwest"}),({"go_southwest"}));
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

int go_southwest() {
  if(present("kguard")) {
    write("The guard forbids your entrance!");
    write("%^MAGENTA%^The guard says:%^RESET%^ You cannot enter the tower, "+TP->query_race()+"!");
    return 0;
  }
  return 1;
}
