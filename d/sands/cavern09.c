#include <std.h>
inherit ROOM;

void create() {
  ::create();
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A sandstone cavern");
  set_long(
"You have reached a dead end in the cavern. An archway leads\n"+
"south to where you can from. The rumbling is considerably louder.");
  set_items(([ "archway":"It is carved of the sandstone that this cavern is created from." ]));
  set_exits(([ "south":"/d/sands/cavern08" ]));
}

void init() {
  ::init();
  if(!present("gate")) new("/d/sands/obj/gate")->move(this_object());
  add_action("check", "check");
}

void reset() {
  ::reset();
  if(!present("guardian")) new("/d/sands/mon/guardian")->move(this_object());
  if(!present("gate")) new("/d/sands/obj/gate")->move(this_object());
}

void check() {return notify_fail("You find no obvious traps.\n");}
