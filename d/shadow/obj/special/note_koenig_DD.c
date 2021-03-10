#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_id(({"paper","note"}));
  set_name("koenig note");
  set_short("A faded note");
  set_long("This is a crumpled piece of paper with some faded writing on it.  "
              "Perhaps you can still read some of it if you try.");
  set_weight(1);
  set_value(0);
}

void init() {
  ::init();
  add_action("read_note","read");
}

int read_note(string str) {
  if(!str) notify_fail("Read what?\n");
  if(str != "note") return 0;
  tell_room(ETP, TPQCN+" reads over the faded note.", TP);
  write("%^YELLOW%^The note reads:  %^RESET%^\n");
  write("%^BOLD%^%^CYAN%^There is no dragon in the nearby caverns so named,\n"
    "Yet danger abounds but so might your fame!\n"
    "The Lady Bandolar would send you there for a mission,\n"
    "Her location and the entrance, of course though, are hidden.\n"
    "Search Shadow 'til you find her and the knowledge she'll share.\n"
    "And the bowels of those caverns... of course, IF you dare.\n");
  return 1;
}
