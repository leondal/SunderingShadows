#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Shadowlord lake");
    set_terrain(SHORE);
    set_travel(FOOT_PATH);
    set_property("fill waterskin",1);
    set_long(
@KAYLA
%^GREEN%^Before you stretches a calm forest lake, its green waters overgrown with
reeds and algae.  At its northern end, a forest river tumbles over a
stone wall and falls into the lake's water, sending ripples out to the 
central depths.  On the south side of the lake, the stream travels back
through the wall of trees into the deep forest.  There seems to be a 
road here, going off through the trees to the east.
KAYLA
    );
    set_listen("default","You hear the sounds of a waterfall to the north.");
    set_smell("default","You can smell the algae from the lake being stirred up.");
    set_exits(([
       "east" : "/d/deku/open/forest45"
    ] ));
    set_items(([
       "lake" : "The lake is of a greenish color.  Maybe you can swim across.",
       "waterfall" : "You catch a glimpse of a cavern behind the waterfall."
    ] ));
}

void init() {
  ::init();
  add_action("swim","swim");
  add_action("enter","enter");
}

int enter(string str) {
  if(!str) {
    write("Enter what?");
    return 1;
  }
  if (str != "waterfall" && str != "cavern") {
    write("You can not enter that!");
    return 1;
  }
  write("You cannot find a way into the cavern or waterfall from this side of "
    "the lake.  Maybe if you were somehow on the other side.");
  return 1;
}

int swim() {
  write("You jump into the green water and start swimming to the other side.");
  say(TPQCN+" dives into the lake and starts to swim across the lake.");
  TP->move_player("/d/deku/open/lake");
  return 1;
}

