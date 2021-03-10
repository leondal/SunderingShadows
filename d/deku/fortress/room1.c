#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(RUBBLE);
    set_short("Sleeping Chamber");
    set_long(
@KAYLA
%^YELLOW%^Sleeping Chamber%^RESET%^
This room was once lavishly furnished, but now the red carpeting
is spoiled, the once rich tapestries are burnt.  Along the wall of
this not so lavishly room lay a number of beds.  Much of the room is
wrecked except for the round table that sits in the center.
KAYLA
    );
    set_listen("default","You hear disconcerting scuffling sounds in surrounding rooms.");
    set_exits(([
       "west" : "/d/deku/fortress/hallN1"
    ] ));
    set_items(([
       "table" : "This table is not like the rest of the room.  It's clean and \n"+
         "the only thing upon the top of the table is a deck \n"+
         "of playing cards.\n"
    ] ));
}

void reset() {
 int i;
  ::reset();
  if(!present("mage") && random(9) >= 5) {
    new("/d/deku/fortress/monster/mage")->move(TO);
  }

  if(!present("guard") && random(10) >= 4) {
     for(i = 0;i < random(4) + 1;i++) {
        new("/d/deku/fortress/monster/guard")->move(TO);
     }
  }
}
