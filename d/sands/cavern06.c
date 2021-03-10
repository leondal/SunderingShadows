#include <std.h>
inherit ROOM;

void create() {
  ::create();
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A sandstone cavern");
  set_long(
"You enter a small 'room' in the cavern. It has been crudely squared off\n"+
"into what could be referred to as walls. There are intricate designs in\n"+
"the walls of the cavern. The runbling gets noticibly louder to the\n"+
"northwest of here.");
  set_items(([ "designs":"They weave in and out of each other, almost like a complex spell." ]));
  set_exits(([ "south":"/d/sands/cavern05",
"northwest":"/d/sands/cavern07" ]));
}

void init() {
  ::init();
  add_action("check", "check");
}

void check() {return notify_fail("You find no obvious traps.\n");}
