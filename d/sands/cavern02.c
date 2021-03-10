#include <std.h>
inherit ROOM;

void create() {
  ::create();
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A sandstone cavern");
  set_long(
"You have ventured just beyond the entrance of this cavern. Faintly glowing\n"+
"sandstone guides your way. The path continues northwest. To the south lies\n"+
"the cavern entrance.");
  set_exits(([
"northwest":"/d/sands/cavern03.c",
"south":"/d/sands/cavern01" ]));
}

void init() {
  ::init();
  if(!present("sign")) new("/d/sands/obj/sign")->move(this_object());
  add_action("check","check");
}

void check() {return notify_fail("You find no obvious traps.\n");}
