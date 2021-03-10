#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(NAT_CAVE);
    set_travel(SLICK_FLOOR);
    set_short("A large, damp cave");
    set_long("You are behind the waterfall and the water comes rushing "
"down from above.  A fine mist spreads from it, keeping the %^GREEN%^mossy "
"floor %^RESET%^damp and slick.  Near the opening you just came through is "
"a ledge that overlooks the %^BOLD%^BLACK%^dark lake %^RESET%^below.  The "
"ledge and cave are well behind where the waterfall pours into the lake "
"and there is a fairly calm, but dark and foreboding, pool about 10 ft. "
"below where you stand.  The cave mouth is 100 ft. wide and 60 ft. high, "
"which leads into the house of Magglerak, a greenhag.  The cavern extends "
"120 ft. into the hill and gradually slopes downward.  The smoke comes "
"from a campfire some 40 ft. into the cave.");
    set_exits(([
       "out" : "/d/deku/open/lake"
    ] ));
    set_pre_exit_functions(({"out"}),({"go_out"}));
    set_items(([
       "campfire":"The campfire, to the north, doesn't light the cave very well.",
       "waterfall":"It pours down into the lake below.",
       ({"ledge", "lake", "water", "pool"}):"The ledge ends over 30 ft. back from "
          "the falling water and is only 10 ft. above the lake's surface.  The "
          "water looks relatively calm just below you except for an occasional "
          "hint of movement under the surface."
    ] ));
    set_listen("default","The sound of the water falling echoes off the walls.");
    set_smell("default","The air smells damp from the spray of the waterfall.");
}

void init() {
  ::init();
  add_action("dive","dive");
}

int go_out() {
  write("You move through the waterfall.\n");
  say(TPQCN+" moves through the waterfall.\n");
  return 1;
}

void reset() {
  ::reset();
  if(!present("hag"))        new("/d/deku/monster/magglerak")->move(TO);
  if(!present("cobra"))      new("/d/deku/monster/cobra")->move(TO);
  if(!present("bugbear")) {
    new("/d/deku/monster/bugbear")->move(TO);
    if(!random(3))  new("/d/deku/monster/bugbear")->move(TO);
  }
}

int dive() {
  if(present("hag")) {
    write("You cannot dive into the water for the seahag stands in your way.");
    return 1;
  }
    write("You take a swan dive into the dirty water");
    say(TPQCN+" dives into the dirty water.");
    TP->move_player("/d/deku/open/underwater");
    return 1;
}
