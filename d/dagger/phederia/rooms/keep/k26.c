#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "Bunkhouse."
  );
  set_long(
  "Bunkhouse.\n"
  "  The north wall of this room is lined with bunks 3 deep to the ceiling."
  "  A curtain covers a passage west and to the east you can see the glow of the kitchen itself."
  "  Splintered wood is all that remains of a heavy wooden door that once covered the south passage."
  "  Debris and personal effects are scatered across the floor as if the bunks lockers have already been searched recently."
  "\n"
  );
  set_smell("default",
  "You can smell something burning."
  );
  set_listen("default",
  "Rats scurry about the corners."
  );
  set_items(([
  "curtain":"A heavy wool curtain hangs over the east doorway.  Its got patches of flour over it and really doesnt look like its worth anything.",
  "rats":"Small grey rodents disapear into the corners when you come to close.",
  "bunks":"Simply but once comfortable bunks line the north wall.  Hooks hang from the wall which once held clothes beside them and lockers are kept on the floor under the rows.",
  "hooks":"The clothes on them are worthless and ransacked.",
  "lockers":"Smashed to a one with their effects scatered about the room.",
  ({"debris","effects","personal effects"}):"The scatered rements of what people once held dear.  There is nothing here that would interest you.",
  ({"door","splintered wood","heavy wooden door","wooden door"}) : "This door looked as if were once barred from the other side and someone wanted through the easiest way possible.  Its been marked by great hacks with what could only have been axes.",
  ]));
  set_exits(([
  "west":KEEP"k25.c",
  "east":KEEP"k27.c",
  "south":KEEP"k33.c",
  ]));
}
