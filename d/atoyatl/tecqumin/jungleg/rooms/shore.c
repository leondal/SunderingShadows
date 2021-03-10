#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../../tecqumin.h"

inherit J_MAZE;

string long_desc();
string true_long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  add_item("river", "The %^BOLD%^%^BLUE%^r%^CYAN%^i%^BLUE%^ver%^RESET%^ flows swiftly past, here. It breaks out of the thick %^GREEN%^j%^BOLD%^u%^RESET%^%^GREEN%^ngle%^RESET%^ with almost no warning, and disappears into more thick %^GREEN%^foliage %^RESET%^just as quickly. It doesn't look like a good place to swim.");
  set_terrain(JUNGLE);
  set_travel(GAME_TRACK);
  set_long( (: TO, "true_long_desc" :) );
}

void init() {
   ::init();
}

string true_long_desc(){
  string result;
  result = long_desc();
  result += " A fast %^BOLD%^%^BLUE%^r%^CYAN%^i%^BLUE%^ver %^RESET%^%^GREEN%^charges past here. It breaks out of the thick jungle with almost no warning, and disappears into more thick f%^BOLD%^o%^RESET%^%^GREEN%^li%^ORANGE%^a%^GREEN%^ge just as quickly.";
  return result;
}
