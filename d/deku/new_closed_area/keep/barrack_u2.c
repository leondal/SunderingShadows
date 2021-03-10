#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("Keep Blacktongue");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_long(
@KAYLA
%^YELLOW%^Captain Quarters %^RESET%^
This is the second floor of the barracks, where the captain of the
guard resides.  The room is about 50 feet across and 15 feet high.
There is a comfortable looking bed in the northwest corner and a
small wooden table stands against the west wall with a padded 
leather chair next to it.
KAYLA
    );
     set_smell("default","Dust and ale permeate the walls of the Keep.");
    set_exits(([ "down" : "/d/deku/keep/barrack2" ] ));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("kcaptain")) {
    new("/d/deku/keep/monster/keep_captain")->move(TO);
  }
  if(!present("kguard")) {
    new("/d/deku/keep/monster/keep_guard")->move(TO);
  }
}
