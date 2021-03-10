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
You are standing outside the hulking Tower of Hawk, just inside 
Keep Blacktongue.  To the south are the gates leading to the forest
outside.  The entrance gate to the tower is here.  Above the gate
sit two stone statues in the shape of gargoyles.  Higher up, maybe
about the fifth floor, light is streaming from a window.
KAYLA
    );
    set_smell("default","Dust and ale permeate the walls of this Keep.");
    set_exits(([
       "south" : "/d/deku/keep/keep1",
       "north" : "/d/deku/keep/tower1"
    ] ));
    set_pre_exit_functions(({"north"}),({"go_north"}));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("klieutenant")) {
    new("/d/deku/keep/monster/keep_lieu")->move(TO);
  }
  if(!present("kguard")) {
    new("/d/deku/keep/monster/keep_guard")->move(TO);
    new("/d/deku/keep/monster/keep_guard")->move(TO);
    new("/d/deku/keep/monster/keep_guard")->move(TO);
  }
}

int go_north() {
  if(present("kguard")) {
    write("%^MAGENTA%^The guard says:%^RESET%^ No one can enter the tower of our lord!");
    return 0;
  }
  return 1;
}
