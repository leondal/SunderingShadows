#include <std.h>
inherit ROOM;

void create() {
  ::create();
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A sandstone cavern");
  set_long(
"You have entered the left fork of the tunnel. The sandstone leads you to\n"+
"the north. You sense that you are going deeper into the world, you have\n"+
"no idea how much deeper, though. The soft rumbling continues.");
  set_exits(([ "north":"/d/sands/cavern06",
"southeast":"/d/sands/cavern04" ]));
}

void init() {
  ::init();
  add_action("check", "check");
}

void check() {return notify_fail("You find no obvious traps.\n");}
