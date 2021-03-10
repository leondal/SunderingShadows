#include <std.h>
inherit ROOM;

void create(){
  ::create();
  set_property("light" , 2);
  set_property("indoors" , 0);
  set_name("Forest Road");
  set_short("%^BOLD%^Forest Road%^RESET%^");
  set_terrain(HEAVY_FOREST);
  set_travel(DIRT_ROAD);
  set_long( (: TO, "ldesc" :) );
  set_smell("default","You smell fresh air and the odor of wildflowers.");
  set_listen("default","Now and then you can hear birds singing.");
  set_exits(([
    "north" : "/d/deku/plains/road02",
    "east" : "/d/deku/plains/plains60"
  ]));
}

string ldesc(string str) {
  return("%^BOLD%^Forest Road%^RESET%^\nThis road leads through a seemingly "
    "quiet forest which seems healthier and more peaceful than that on the "
    "rest of the island.  The forest is fairly dense here but the road is well "
    "defined and visible for a good distance.  The road has been maintained "
    "well enough the forest doesn't overrun it but clearly is not heavily "
    "travelled.");
}