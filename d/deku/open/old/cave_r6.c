#include <std.h>

inherit "/d/deku/open/cave_r3i.c";

void create() {
    ::create();
    set_exits(([
       "east" : "/d/deku/open/ogre",
       "north" : "/d/deku/open/kitchen"
    ] ));
   set_smell("default", "Something to the north smells really rancid.");
}

void reset() {
  ::reset();
}
