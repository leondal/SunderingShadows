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
This is the eastern part of the Keep.  Toward the west is some
kind of magic shop with a sign:  Gareth's Magic.  To the east is
another guard tower.  The cobblestone path continues to the 
north and south.
KAYLA
    );
    set_exits(([
       "west" : "/d/deku/keep/magic",
       "east" : "/d/deku/keep/towerE1i",
       "south" : "/d/deku/keep/keepE3",
       "north" : "/d/deku/keep/keepE5"
    ] ));
    set_pre_exit_functions(({"east"}),({"go_east"}));
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

int go_east() {
  if(present("kguard")) {
    write("The guard forbids your entrance into the tower!");
    write("%^MAGENTA%^The guard says:%^RESET%^ The tower is forbidden from the likes of you "+TP->query_race()+"!");
    return 0;
  }
  return 1;
}
