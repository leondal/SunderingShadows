#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Road to Verbobone");
    set_name("Road to Verbobone");
    set_property("light",1);
    set_property("indoors",0);
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_long( (: TO, "ldesc" :) );
    set_listen("default","Peculiar, the forest is deadly quiet.");
    set_smell("default","You smell the decaying of the forest.");
    set_items(( [
      "trees" : "The tree limbs are gnarled and their leaves faded.  Perhaps "
        "the fog is smothering them or evil is simply too strong here to "
        "allow them to flourish.",
      "fog" : "Even a sunny day doesn't seem to break its hold on the forest.",
    ] ));
    set_exits(([
       "west" : "/d/deku/open/dforest1",
       "east" : "/d/deku/open/dforest3"
    ] ));
}

string ldesc(string str) {
  return("An old footpath has turned into more of a dirt road from the steady "
    "travel of adventurers through this section of the forest.  The "
    "trees look quite old with their knotted limbs and faded leaves, and you "
    "see no signs of wildlife.  All around you, thick fog seems to blanket the "
    "forest like a misty gray cloak.");
}
