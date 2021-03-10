#include <std.h>
inherit ROOM;

void create() {
  ::create();
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A sandstone cavern");
  set_long(
"You are standing in the middle of a large section of this cavern. A section\n"+
"of sandstone has been fashioned into an archway to the north. The rumbling\n"+
"seems to be coming from in there.");
  set_items(([ "archway":"It is a large section of the cavern, carved into a doorway of sorts." ]));
  set_exits(([ "north":"/d/sands/cavern09",
"southwest":"/d/sands/cavern07" ]));
}

void init() {
  ::init();
  add_action("check", "check");
}

void check() {return notify_fail("You find no obvious traps.\n");}
