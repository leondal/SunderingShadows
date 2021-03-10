#include <std.h>
inherit ROOM;

int open;


void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_short("Warrior's tomb");
    set_long(
@KAYLA
As you enter this large cavern, you notice that the maroon walls
contrast with the white alabaster floor.  In the center of the
cavern, lying east to west, is a large stone sarcophagus.  The
finely carved death mask suggests a noble warrior.
KAYLA
    );
     set_smell("default","The air in this cavern is stale and heavy.");
    set_exits(([
       "south" : "/d/deku/dark/lizard"
    ] ));
    set_items(([
      ({"sarcophagus","tomb"}) : "Here rests a noble warrior of the darkelf cult.\n"+
               "The tomb seems as if no one has ever tampered with\n"+
               "it.  So I wouldn't open it.\n"
    ] ));
  open = 0;
}

void init () {
  ::init();
  add_action("open_it", "open");
}

int open_it(string str) {
  if (!str) {
    notify_fail("Open what?\n");
    return 0;
  }
  if (str != "tomb") {
    notify_fail("You can not open that!\n");
    return 0;
  }
  if (open) return notify_fail("It is open already.\n");
  open = 1;

  write("As you open the tomb of the mighty noble warrior, death");
  write("in the form of white fog rushes out from under the lid and");
  write("covers the earthy floor below.");
  write("\n");
  write("The fog gathers in the center of the room and the noble warrior");
 write("appears through the dense fog.");
  say(this_player()->query_cap_name()+" opens the lid to the sarcophagus.\n");
  say("Fog rushes out of the tomb and gather in the center of the room,");
  say("revealing the warrior as it rushes to attack.");
  new("/d/deku/monster/warrior2")->move(TO);
  return 1;
}

void reset() {
  ::reset();
  if(open) {
    open =0;
    return 1;
  }
}
