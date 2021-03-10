#include <std.h>

inherit "/d/deku/open/cave_r3i.c";

void create() {
    ::create();
    set_exits(([
       "south" : "/d/deku/open/rec",
      "west" : "/d/deku/open/cave_r5",
       "east" : "/d/deku/open/cave_r3i"
    ] ));
    set_pre_exit_functions(({"west"}),({"go_west"}));
}


int go_west() {
  if(avatarp(TP) && TP->query_invis())  return 1;
  if(present("ogre guard")) {
    write("The Ogre blocks the way completely.");
    return 0;
  }
  return 1;
}
