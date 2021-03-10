#include <std.h>

inherit "/d/deku/open/forest42i";

void create() {
    ::create();
    set_exits(([
       "west" : "/d/deku/open/forest62",
       "east" : "/d/deku/open/forest6"
    ] ));
    set_pre_exit_functions(({"west"}),({"go_dir"}));
    set_pre_exit_functions(({"east"}),({"go_dir"}));
    set_items(([
    ] ));
}

int go_dir() {
  int n;
  n = random(10);
  if(!present("bandit")) {
    if (n > 8) {
      write("You are surprised by bandits!");
      say(TPQCN+" is surprised by bandits!");
      new("/d/deku/monster/bandit")->move(TO);
      new("/d/deku/monster/bandit")->move(TO);
      return 0;
    }
  }
  return 1;
}
