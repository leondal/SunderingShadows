#include <std.h>
#include <objects.h>
#include "kai.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(GRASSLANDS);
   set_travel(DIRT_ROAD);
    set_property("light",2);
    set_property("indoors",0);
    set_short("Along a dusty road");
    set_long(
@KAYLA
This is a long dusty road that is running straight through the main
part of the village.  Destroyed houses border the road.  One building
to the east looks less destroyed than the rest.
KAYLA
    );
    set_exits(([
      "north" : "/d/koenig/village/dusty3",
       "south" : "/d/koenig/village/dusty7",
      "east" : "/d/koenig/village/genstore"
    ] ));
    set_items(([
       "houses" : "They are burned down and destroyed.",
       "house" : "It looks like it may be a general store."
    ] ));
}

void init() {
  ::init();
  do_random_encounters( ({
    MONDIR+"orc",
    MONDIR+"orcguard"
  }), 50,2);
}
