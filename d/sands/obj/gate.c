#include <std.h>
inherit OBJECT;

void create() {
  ::create();
  set_name("gate");
  set_id(({ "gate", "gateway", "door" }));
  set_short("A gateway");
  set_long(
"This large stone archway rumbles with power. It's glossy center spikes\n"+
"with magical lighting. You sense this will take you to a whole nother\n"+
"world. You may <warp gate> to another place with it.");
  set_weight(0);
  set_value(0);
}

get() {return 0;}

void init() {
  ::init();
  add_action("enter", "warp");
}

void enter(string arg) {
  if(id(arg)) {
    if(present("guardian")) return notify_fail("The guardian blocks your passage.\n");
    write("The Ruins of Underhaven aren't open to the public, yet.\n"+
          "We're sorry for the inconvenience.\n"+
          "     -Tebryn");
    return 1;
  }

}
