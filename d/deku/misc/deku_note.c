#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_id(({"paper","note"}));
  set_name("deku note");
  set("short", "A note");
  set("long", "This is a note with some crude writing on it.");
  set_weight(0);
  set_value(0);
}

void init() {
  ::init();
  add_action("read_note","read");
}

int read_note(string str) {
  if(!str) notify_fail("Read what?\n");
  if(str != "note") return 0;
  write("%^RED%^The note reads:     %^RESET%^");
  TP->more("/d/deku/misc/NOTE");
  return 1;
}
