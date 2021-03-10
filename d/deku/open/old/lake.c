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
through the wall of trees into the deep forest.
KAYLA
    );
    set_listen("default","You hear the sounds of a waterfall to the north.");
    set_smell("default","You can smell the algae from the lake being stirred up.");
    set_exits(([
       "west" : "/d/deku/open/forest41"
    ] ));
    set_items(([
       "lake" : "The lake is of a greenish color.  Maybe you can swim across.",
       "waterfall" : "You notice a cavern under the waterfall which winds underground beneath the lake.  It looks like you might be able to enter it."
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
  write("You move towards the waterfall and enter from behind it.\n");
  say(TPQCN+" moves towards the waterfall and disappears behind its rushing water.");
  TP->move_player("/d/deku/open/cave");
  return 1;
}

int swim() {
  write("You jump into the green water and start swimming to the other side.\n");
  say(TPQCN+" dives into the lake and starts to swim to the other side.");
  TP->move_player("/d/deku/open/lake2");
  return 1;
}
