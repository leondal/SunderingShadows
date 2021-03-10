#include <std.h>
inherit ROOM;

void create() {
  ::create();
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A sandstone cavern");
  set_long(
"You have come to a fork in the cavern. To the northwest the path leads to\n"+
"a soft rumbling sound. The northeastern path leads to a wider tunnel.");
  set_exits(([ "northwest":"/d/sands/cavern05",
"northeast":"/d/sands/cavern10",
"south":"/d/sands/cavern03" ]));
}

void init() {
  ::init();
  add_action("check","check");
}

void check() {return notify_fail("You find no obvious traps.\n");}
