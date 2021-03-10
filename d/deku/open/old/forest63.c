#include <std.h>

inherit "/d/deku/open/forest42i";

void create() {
    ::create();
    set_long(TO->query_long()+"There seems to be a small clearing to the "
       "north.\n");
    set_exits(([
       "north" : "/d/deku/open/path",
       "east" : "/d/deku/open/forest62"
    ] ));
    set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
    set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));
    set_items(([
    ] ));
}

int GoThroughDoor() {
  int n;
  n = random(10);
  if(!present("bandit")) {
    if(n > 8) {
      write("You are surprised by bandits!");
      say(TPQCN+" is surprised by bandits!");
      new("/d/deku/monster/bandit")->move(TO);
      new("/d/deku/monster/bandit")->move(TO);
      return 0;
    }
  }
  return 1;
}
