#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Corridor of Heads");
    set_long(
@KAYLA
%^YELLOW%^Chamber of Heads%^RESET%^
In this chamber, you see the horrible sight of six heads sitting
atop 6' spikes.  Three of the heads sit along the north wall and 3
against the south wall.  In the center is a stone altar covered 
in dried and dripping blood.  The atmosphere in this chamber  
is cold and damp.
KAYLA
    );
     set_smell("default","The smell of death and decay is throughout this corridor.");
    set_exits(([
       "west" : "/d/deku/fortress/hallN5"
    ] ));
    set_items(([
       "heads" : "These heads are the macabre remains of humans whose lives have been taken to feed the Master of Darkness."
    ] ));
}

void reset() {
  ::reset();
  if(!present("nightmare")) {
    new("/d/deku/fortress/monster/nightmare")->move(TO);
  }
}
