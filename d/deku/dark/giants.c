#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_short("Giant Cobra's play room");
    set_long(
@KAYLA
This cavern has the smell and looks of a place where paricularly dirty,
ogre-like monsters would live.  You note that the cave is irregularly
shaped and has no apparent entrance other than the passage by which
you entered.  There are some bones and skulls strewn around.  You also
see a flat rock which appears to have been used as a table.
KAYLA
    );
    set_listen("default","You hear arguing to the west.");	
    set_smell("default","You smell blood and raw flesh from the half-eaten corpse.");
    set_exits(([
       "west" : "/d/deku/dark/group"
    ] ));
    set_items(([
       ({"rock", "table"}) : "The rock table still has the remains of half eaten dwarf upon it, as if it were being carved for dinner"
    ] ));
}

void reset() {
  ::reset();
  if(!present("cobra")) {
    new("/d/deku/monster/cobra")->move(TO);
    new("/d/deku/monster/ogre3")->move(TO);
  }
  if(!random(3)) {
    if(!present("cloud")) new("/d/deku/monster/cloud")->move(TO);
    if(!present("ogre")) new("/d/deku/monster/ogre")->move(TO);
  }
}
